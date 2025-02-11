PPB_Buffer_Proxy::~PPB_Buffer_Proxy() {
    delete[] buffer_; 
    buffer_ = nullptr;
}