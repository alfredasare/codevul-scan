void ipc_free(void* ptr, int size)
{
    if(size > 0 && size <= PAGE_SIZE) {
        kfree(ptr);
    } else {
        // Handle invalid size or size greater than PAGE_SIZE
        // For example, log an error or return an error code
    }
}