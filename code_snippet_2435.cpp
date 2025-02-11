flush_signal_handlers(struct task_struct *t, int force_default)
{
    int i;
    struct k_sigaction *ka = &t->sighand->action[0];
    for (i = _NSIG ; i!= 0 ; i--) {
        struct k_sigaction *ka_copy = ka; // Create a copy of ka
        if (force_default || ka_copy->sa.sa_handler!= SIG_IGN)
            ka_copy->sa.sa_handler = SIG_DFL;
        ka_copy->sa.sa_flags = 0;
        sigemptyset(&ka_copy->sa.sa_mask); // Call sigemptyset on each iteration
        ka++;
    }
}