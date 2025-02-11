int get_camera_metadata_ro_entry(const camera_metadata_t *src, size_t index, camera_metadata_ro_entry_t *entry) {
    if (!src || !entry) {
        return -1;
    }

    if (index >= src->count) {
        return -1;
    }

    return get_camera_metadata_entry((camera_metadata_t*)src, index, (camera_metadata_entry_t*)entry);
}