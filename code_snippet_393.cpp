void i8042_lock_chip(void)
{
	mutex_lock(&i8042_mutex);
	mutex_unlock(&i8042_mutex);
}