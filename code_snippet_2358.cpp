static void __exit bnep_exit(void)
{
    char buffer[128]; // Reasonable buffer size
    int len = strlen(buffer); // Get the length of the buffer

    if (len > sizeof(buffer)) {
        // Buffer overflow detected, exit or handle error
        return;
    }

    bnep_sock_cleanup();
}