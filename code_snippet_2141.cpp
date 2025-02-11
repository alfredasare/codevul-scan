void XMPChunk::changesAndSize( RIFF_MetaHandler* handler )
{
    size_t newSize = 8 + handler->xmpPacket.size(); 
    XMP_Enforce( &handler->xmpPacket!= 0 );
    XMP_Enforce( handler->xmpPacket.size() > 0 );
    XMP_Validate( newSize <= std::numeric_limits<size_t>::max(), "no single chunk may be above 4 GB", kXMPErr_InternalFailure );
    this->newSize = newSize;
    this->hasChange = true;
}