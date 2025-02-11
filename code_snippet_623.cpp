bool omx_venc::dev_free_buf(void *buf_addr, unsigned port)
{
if (handle != nullptr) // Check if handle is not null before dereferencing
return handle->venc_free_buf(buf_addr, port);
else
return false; // Or any other appropriate error handling
}