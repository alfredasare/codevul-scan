sp<MediaSource> ATSParser::Program::getSource(SourceType type) {
    size_t index = 0;

    for (size_t i = 0; i < mStreams.size(); ++i) {
        sp<MediaSource> source = mStreams[i]->getSource(type);
        if (source!= NULL) {
            return source;
        }
    }

    return NULL;
}