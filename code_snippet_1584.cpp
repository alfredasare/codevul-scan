nfs_available(void)
{
        int lock_fd;

        if (nfs_exportfs_temp_fd == -1) {
                (void) nfs_check_exportfs();
                return B_FALSE;
        }

        /* Acquire an exclusive lock on /path/to/lockfile */
        lock_fd = open("/path/to/lockfile", O_RDONLY | O_EXCL);
        if (lock_fd == -1) {
                /* Handle error */
                return B_FALSE;
        }

        /* Check the value of nfs_exportfs_temp_fd while holding the lock */
        if (nfs_exportfs_temp_fd != -1) {
                close(lock_fd);
                return B_TRUE;
        }

        close(lock_fd);
        return B_FALSE;
}