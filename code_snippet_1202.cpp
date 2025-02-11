const EVP_MD *tls12_get_hash(unsigned char hash_alg)
{
    static const unsigned char supported_algorithms[] = {
        TLSEXT_hash_sha1,
        TLSEXT_hash_sha224,
        TLSEXT_hash_sha256,
        TLSEXT_hash_sha384,
        TLSEXT_hash_sha512
    };

    if (std::find(std::begin(supported_algorithms), std::end(supported_algorithms), hash_alg) == std::end(supported_algorithms)) {
        return NULL;
    }

    switch (hash_alg) {
        case TLSEXT_hash_sha1:
            return EVP_sha1();
        case TLSEXT_hash_sha224:
            return EVP_sha224();
        case TLSEXT_hash_sha256:
            return EVP_sha256();
        case TLSEXT_hash_sha384:
            return EVP_sha384();
        case TLSEXT_hash_sha512:
            return EVP_sha512();
        default:
            return NULL;
    }
}