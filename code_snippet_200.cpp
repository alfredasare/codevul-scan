handle_bytes_write(int handle)
{
    // Check if the handle value is within the valid index range
    if (handle < 0 || handle >= HANDLE_MAX) {
        return -1;
    }

    if (handle_is_ok(handle, HANDLE_FILE)) {
        return (handles[handle].bytes_write);
    }
    return 0;
}