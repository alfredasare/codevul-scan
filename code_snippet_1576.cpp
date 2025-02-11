sp<MediaSource> ATSParser::Program::getSource(SourceType type) {
    size_t index = (type == AUDIO) ? 0 : 0;

    for (size_t i = 0; i < mStreams.size(); ++i) {
        sp<MediaSource> source = mStreams.editValueAt(i)->getSource(type);
        if (source) { // Add null check here
            if (index == 0) {
                return source;
            }
            --index;
        }
    }

    return nullptr; // Return an appropriate error value or throw an exception instead of returning NULL
}