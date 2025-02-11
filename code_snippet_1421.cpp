struct cred *prepare_creds(void)
{
    struct task_struct *task = current;
    const struct cred *old;
    struct cred new_cred;

    validate_process_creds();

    new_cred = kmemdup(old = task->cred, sizeof(struct cred), GFP_KERNEL);
    if (!new_cred)
        return NULL;

    //...
}