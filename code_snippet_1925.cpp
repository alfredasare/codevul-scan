int get_camera_metadata_ro_entry(const camera_metadata_t *src, size_t index, camera_metadata_ro_entry_t *entry) {
    if (!src || index >= src->size ||!entry) {
        return -EINVAL;
    }
    if ((uintptr_t)entry % sizeof(camera_metadata_ro_entry_t)!= 0) {
        return -EFAULT;
    }
    return get_camera_metadata_entry((camera_metadata_t*)src, index, (camera_metadata_entry_t*)entry);
}