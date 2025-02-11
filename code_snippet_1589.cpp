Fclose(pointer iop) {
    if (!IsValidFilePointer(iop)) {
        return -1;
    }

    char sanitized_path[256];
    snprintf(sanitized_path, sizeof(sanitized_path), "/path/to/default/folder/%s", "");
    return fclose(freopen(sanitized_path, "w", iop));
}