static int crypto_init_aes_ops_sync(struct crypto_tfm *tfm)
{
    struct aes_tfm *crt = &tfm->crt_aes;
    struct aes_alg *alg = &tfm->__crt_alg->cra_aes;
    unsigned long align = crypto_tfm_alg_alignmask(tfm) + 1;
    unsigned long addr;

    crt->setkey = aes_setkey_aes;
    crt->encrypt = alg->aes_encrypt;
    crt->decrypt = alg->aes_decrypt;

    addr = (unsigned long)crypto_tfm_ctx(tfm);
    addr = ALIGN(addr, align);
    addr += ALIGN(tfm->__crt_alg->cra_ctxsize, align);
    crt->iv = (void *)addr;

    return 0;
}