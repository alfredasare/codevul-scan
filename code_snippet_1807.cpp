int sort_camera_metadata(camera_metadata_t *dst) {
    if (dst == NULL) return ERROR;
    if (dst->flags & FLAG_SORTED) return OK;

    // Check if entry_count is within the allocated size of the get_entries(dst) buffer
    if (dst->entry_count >= 0 && dst->entry_count < dst->size / sizeof(camera_metadata_buffer_entry_t)) {
        qsort(get_entries(dst), dst->entry_count,
            sizeof(camera_metadata_buffer_entry_t),
            compare_entry_tags);
    } else {
        // Handle error condition, e.g., return an error code or log an error message
        return ERROR;
    }

    dst->flags |= FLAG_SORTED;

    assert(validate_camera_metadata_structure(dst, NULL) == OK);
    return OK;
}