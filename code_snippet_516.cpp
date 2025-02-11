bool omx_venc::dev_free_buf(void *buf_addr,unsigned port)
{
    try {
        return handle->venc_free_buf(buf_addr,port);
    } catch (const std::exception& e) {
        std::cerr << "Error freeing buffer" << std::endl;
        return false;
    }
}