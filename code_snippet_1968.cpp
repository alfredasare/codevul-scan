static unsigned int snd_timer_user_poll(struct file *file, poll_table * wait)
{
        unsigned int mask;
        struct snd_timer_user *tu;

        if (!file || !(tu = file->private_data) || !tu->qused)
                return