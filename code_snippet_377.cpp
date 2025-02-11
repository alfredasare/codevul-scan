static int quitmsg_is_split(const char *reason)
{
    static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    static bool split = false;

    pthread_mutex_lock(&lock);
    bool new_split = /* update the split status based on the current data structure */;
    split = new_split;
    pthread_mutex_unlock(&lock);

    return split;
}