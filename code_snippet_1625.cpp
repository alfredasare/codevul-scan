FLACParser::~FLACParser()
{
    ALOGV("FLACParser::~FLACParser");
    if (mDecoder != nullptr) {
        FLAC__stream_decoder_delete(mDecoder);
        mDecoder = nullptr;
    }
}