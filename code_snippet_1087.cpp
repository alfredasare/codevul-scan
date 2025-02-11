Here's the fixed version of the vulnerable code following the provided recommendation:


int xt_register_targets(struct xt_target *target, unsigned int n)
{
	unsigned int i;
	int temp_reg_count = 0;
	int err = 0;

	for (i = 0; i < n; i++) {
		err = xt_register_target(&target[i]);