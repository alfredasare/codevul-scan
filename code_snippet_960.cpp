FLAC__StreamDecoderReadStatus file_read_callback_(const FLAC__StreamDecoder *decoder, FLAC__byte buffer[], size_t *bytes, void *client_data)
{
    (void)client_data;

    const char *file_path = decoder->private_->file->filename;
    char canonical_path[1024];
    realpath(file_path, canonical_path);

    // Check if the path is within the intended directory
    if (strcmp(canonical_path, decoder->private_->base_dir)!= 0) {
        return FLAC__STREAM_DECODER_READ_STATUS_ABORT;
    }

    if (*bytes > 0) {
        *bytes = fread(buffer, sizeof(FLAC__byte), *bytes, decoder->private_->file);
        if (ferror(decoder->private_->file)) {
            return FLAC__STREAM_DECODER_READ_STATUS_ABORT;
        } else if (*bytes == 0) {
            return FLAC__STREAM_DECODER_READ_STATUS_END_OF_STREAM;
        } else {
            return FLAC__STREAM_DECODER_READ_STATUS_CONTINUE;
        }
    } else {
        return FLAC__STREAM_DECODER_READ_STATUS_ABORT;
    }
}