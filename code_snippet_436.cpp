void crypto_unregister_rng(struct rng_alg *alg)
{
    if (sizeof(struct crypto_alg) == sizeof(alg->base))
        crypto_unregister_alg(&alg->base);
}