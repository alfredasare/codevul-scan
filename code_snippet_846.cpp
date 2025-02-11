OMX::buffer_id OMXNodeInstance::makeBufferID(OMX_BUFFERHEADERTYPE *bufferHeader) {
int64_t bufferID = static_cast<int64_t>(bufferHeader);
if (bufferID > std::numeric_limits<OMX::buffer_id>::max()) {
throw std::runtime_error("Buffer ID overflow");
}
return static_cast<OMX::buffer_id>(bufferID);
}