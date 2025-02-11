static void get_id3_tag(AVFormatContext *s, const char *len)
{
    ID3v2ExtraMeta *id3v2_extra_meta = NULL;
    const char *allowed_dirs[] = {"/path/to/trusted/directory", "/path/to/another/trusted/directory"};
    const int allowed_dirs_count = sizeof(allowed_dirs) / sizeof(allowed_dirs[0]);

    // Validate and sanitize the len parameter
    if (strlen(len) > MAX_PATH_LENGTH ||!is_valid_chars(len)) {
        return; // error handling
    }

    // Construct the file path using the allowed directories
    char file_path[PATH_MAX];
    for (int i = 0; i < allowed_dirs_count; i++) {
        strcpy(file_path, allowed_dirs[i]);
        strcat(file_path, "/");
        strcat(file_path, len);
        ff_id3v2_read(s, ID3v2_DEFAULT_MAGIC, &id3v2_extra_meta, file_path);
        if (id3v2_extra_meta) {
            ff_id3v2_parse_apic(s, &id3v2_extra_meta);
            ff_id3v2_parse_chapters(s, &id3v2_extra_meta);
        }
        ff_id3v2_free_extra_meta(&id3v2_extra_meta);
    }
}