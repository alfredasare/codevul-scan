pthread_mutex_t g_afs_gcpags_mutex = PTHREAD_MUTEX_INITIALIZER;

DECL_PIOCTL(PGCPAGs)
{
    int result;

    pthread_mutex_lock(&g_afs_gcpags_mutex);
    if (!afs_osi_suser(*acred)) {
        result = EACCES;
    } else {
        afs_gcpags = AFS_GCPAGS_USERDISABLED;
        result = 0;
    }
    pthread_mutex_unlock(&g_afs_gcpags_mutex);

    return result;
}