static void security\_salted\_hash(const BYTE\* salt, const BYTE\* input, int length,
const BYTE\* salt1, const BYTE\* salt2, BYTE\* output)
{
crypto\_md5\_t md5;
crypto\_sha1\_t sha1;
size\_t sha1\_digest\_len = CRYPTO\_SHA1\_DIGEST\_LENGTH;

/* SaltedHash(Salt, Input, Salt1, Salt2) = MD5(S + SHA1(Input + Salt + Salt1 + Salt2)) */

/* SHA1\_Digest = SHA1(Input + Salt + Salt1 + Salt2) */
sha1 = crypto\_sha1\_init();
crypto\_sha1\_update(sha1, input, length); /* Input */
crypto\_sha1\_update(sha1, salt, 48); /* Salt (48 bytes) */
crypto\_sha1\_update(sha1, salt1, 32); /* Salt1 (32 bytes) */
crypto\_sha1\_update(sha1, salt2, 32); /* Salt2 (32 bytes) */
crypto\_sha1\_final(sha1, output, &sha1\_digest\_len);

/* SaltedHash(Salt, Input, Salt1, Salt2) = MD5(S + SHA1\_Digest) */
md5 = crypto\_md5\_init();
crypto\_md5\_update(md5, salt, 48); /* Salt (48 bytes) */
crypto\_md5\_update(md5, output, sha1\_digest\_len); /* SHA1\_Digest */
crypto\_md5\_final(md5, output);
}