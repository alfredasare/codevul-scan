void HEVC_RewriteESDescriptor(GF_MPEGVisualSampleEntryBox *hevc)
{
    if (!hevc || !hevc->decoderConfigRecord) {
        // Handle error condition: the pointer or its member is null
        return;
    }
    
    HEVC_RewriteESDescriptorEx(hevc, hevc->decoderConfigRecord);
}