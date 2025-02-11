int crypto_register_skcipher(struct skcipher_alg *alg)
{
	struct crypto_alg base = { };
	int err;

	if (!alg || !alg->base.cra_name || !alg->base.cra_driver_name ||
	    !alg->base.cra_blocksize || !alg->base.cra_ctxsize ||
	    !alg->base.cra_alignmask || !alg->encrypt || !alg->decrypt ||
	    !alg->base.cra_u.skcipher.min_keysize ||
	    alg->base.cra_u.skcipher.max_keysize < alg->base.cra_u.skcipher.min_keysize)
		return -EINVAL;

	memcpy(&base, alg, sizeof(base));

	err = skcipher_prepare_alg(alg);
	if (err)
		return err;

	return crypto_register_alg(&base);
}