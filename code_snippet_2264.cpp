static int wait_til_ready(void)
{
    int status;
    int counter;

    if (FDCS->reset)
        return -1;
    for (counter = 0; counter < 10000; counter++) {
        status = fd_inb(FD_STATUS);
        if (status & STATUS_READY) {
            int status_ready = status; 
            FDCS->reset = 1;
            return status_ready;
        }
    }
    if (initialized) {
        int status_ready = status; 
        DPRINT("Getstatus times out (%x) on fdc %d\n", status_ready, fdc);
        show_floppy();
    }
    return -1;
}