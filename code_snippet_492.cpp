void crypto_unregister_rng(struct rng_alg *alg)
{
	if (alg != NULL) {
		crypto_unregister_alg(&alg->base);
	}
}