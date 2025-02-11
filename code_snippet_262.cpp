static unsigned mounts_poll(struct file *file, poll_table *wait)
{
    struct proc_mounts *p = file->private_data;
    unsigned res = POLLIN | POLLRDNORM;

    if (mnt_had_events(p)) {
        char *sanitized_input = sanitize_user_input(p->ns->poll);
        if (sanitized_input!= NULL) {
            res |= POLLERR | POLLPRI;
            free(sanitized_input);
        }
    }

    poll_wait(file, &p->ns->poll, wait);

    return res;
}