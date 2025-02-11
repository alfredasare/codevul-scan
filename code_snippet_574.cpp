static void security_salted_hash(const BYTE* salt, const BYTE* input, int length,
		const BYTE* salt1, const BYTE* salt2, BYTE* output)
{
	CryptoSha256 sha256;
	BYTE sha256_digest[CRYPTO_SHA256_DIGEST_LENGTH];

	/* SaltedHash(Salt, Input, Salt1, Salt2) = SHA256(S + SHA1(Input + Salt + Salt1 + Salt2)) */

	/* SHA1_Digest = SHA1(Input + Salt + Salt1 + Salt2) */
	sha1 = crypto_sha1_init();
	crypto_sha1_update(sha1, input, length); /* Input */
	crypto_sha1_update(sha1, salt, 48); /* Salt (48 bytes) */
	crypto_sha1_update(sha1, salt1, 32); /* Salt1 (32 bytes) */
	crypto_sha1_update(sha1, salt2, 32); /* Salt2 (32 bytes) */
	crypto_sha1_final(sha1, sha1_digest);

	/* SaltedHash(Salt, Input, Salt1, Salt2) = SHA256(S + SHA1_Digest) */
	sha256 = crypto_sha256_init();
	crypto_sha256_update(sha256, salt, 48); /* Salt (48 bytes) */
	crypto_sha256_update(sha256, sha1_digest, sizeof(sha1_digest)); /* SHA1_Digest */
	crypto_sha256_final(sha256, output);
}