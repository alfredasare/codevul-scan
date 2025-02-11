int sort_camera_metadata(camera_metadata_t *dst) {
    if (dst == NULL) return ERROR;
    if (dst->flags & FLAG_SORTED) return OK;

    camera_metadata_buffer_entry_t *entries = get_entries(dst);
    size_t entry_count = dst->entry_count;
    if (entry_count > 0) {
        qsort(entries, entry_count, sizeof(camera_metadata_buffer_entry_t), compare_entry_tags);
        dst->flags |= FLAG_SORTED;
    }

    assert(validate_camera_metadata_structure(dst, NULL) == OK);
    return OK;
}