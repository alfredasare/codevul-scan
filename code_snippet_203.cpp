void __put_user_ns(struct user_namespace *ns)
{
    spin_lock(&ns->work_lock);
    schedule_work(&ns->work);
    spin_unlock(&ns->work_lock);
}