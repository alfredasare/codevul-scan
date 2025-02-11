#define ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))

unsigned long copy_fpr_from_user(struct task_struct *task, void __user *from)
{
	u64 buf[ELF_NFPREG];
	int i;

	if (__copy_from_user(buf, from, ELF_NFPREG * sizeof(double)))
		return 1;

	for (i = 0; i < ARRAY_SIZE(buf); i++) {
		if (i == (ARRAY_SIZE(buf) - 1))
			task->thread.fp_state.fpscr = buf[i];
		else
			task->thread.TS_FPR(i) = buf[i];
	}

	return 0;
}