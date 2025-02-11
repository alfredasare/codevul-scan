static int esil_6502_fini (RAnalEsil *esil) {
    // Example: close file descriptor
    if (esil->fd != -1) {
        close(esil->fd);
        esil->fd = -1;
    }

    // Example: free memory
    if (esil->buffer) {
        free(esil->buffer);
        esil->buffer = NULL;
    }

    // After cleanup, return true
    return true;
}