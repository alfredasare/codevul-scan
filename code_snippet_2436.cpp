PPB_Buffer_Proxy::~PPB_Buffer_Proxy() {
    delete[] buffer;
    buffer = nullptr;
    // Close any file handles, network sockets, or other resources here
}