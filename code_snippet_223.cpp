int output_mute_changed_count() const {
    if (output_mute_changed_count_ < 0 || output_mute_changed_count_ > MAX_OUTPUT_MUTE_CHANGED_COUNT) {
        // Handle invalid value or throw an exception
        //...
    }
    return output_mute_changed_count_;
}