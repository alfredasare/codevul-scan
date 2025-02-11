OMX::buffer_id OMXNodeInstance::makeBufferID(OMX_BUFFERHEADERTYPE *bufferHeader) {
    if (bufferHeader == NULL || bufferHeader->nSize < sizeof(OMX_BUFFERHEADERTYPE)) {
        throw std::invalid_argument("Invalid buffer header");
    }
    return (OMX::buffer_id)bufferHeader;
}