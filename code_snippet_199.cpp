int handle_bytes_write(int handle)
{
    int result = 0;

    if (handle_is_ok(handle, HANDLE_FILE))
    {
        result = handles[handle].bytes_write;
    }
    else
    {
        return -1; // or throw an exception, log the error, etc.
    }

    return result;
}