static int __init cast5_mod_init(void)
{
	rwlock_write_lock(&crypto_lock);
	int retval = crypto_register_alg(&alg);
	rwlock_write_unlock(&crypto_lock);
	return retval;
}
module_init(cast5_mod_init);