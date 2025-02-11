char *enl_send_and_wait(char *msg)
{
    char *reply = IPC_TIMEOUT;
    sighandler_t old_alrm;

    //...
    old_alrm = (sighandler_t) signal(SIGALRM, (sighandler_t) enl_ipc_timeout);
    //...
}