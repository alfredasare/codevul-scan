static void crypto_skcipher_free_instance(struct crypto_instance *inst)
{
    struct skcipher_instance *skcipher = NULL;

    if (inst!= NULL) {
        skcipher = container_of(inst, struct skcipher_instance, s.base);
        skcipher->free(skcipher);
    }
}