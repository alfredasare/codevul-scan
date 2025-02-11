void HEVC_RewriteESDescriptor(GF_MPEGVisualSampleEntryBox *hevc)
{
    if (hevc == NULL || hevc->esdescriptorbuffer == NULL) {
        // Handle error or return early
    }

    size_t buffer_size = hevc->esdescriptorbuffer->size;
    if (buffer_size < expected_data_size) {
        // Handle error or return early
    }

    size_t expected_copy_size = sizeof(some_expected_data_type);
    if (buffer_size < expected_copy_size) {
        // Handle error or return early
    }

    char* buffer = hevc->esdescriptorbuffer->buffer;
    HEVC_RewriteESDescriptorEx(hevc, buffer, expected_copy_size);
}