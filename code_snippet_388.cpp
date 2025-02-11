unsigned long copy_fpr_from_user(struct task_struct *task, void __user *from)
{
    u64 buf[ELF_NFPREG];
    int i;
    size_t from_len = ELF_NFPREG * sizeof(double);

    if (from_len > PAGE_SIZE) {
        return -EINVAL;
    }

    if (__copy_from_user_kuser(buf, from, from_len)) {
        return 1;
    }

    memset(buf, 0, sizeof(buf));

    for (i = 0; i < (ELF_NFPREG - 1); i++) {
        task->thread.TS_FPR(i) = buf[i];
    }
    task->thread.fp_state.fpscr = buf[i];

    return 0;
}