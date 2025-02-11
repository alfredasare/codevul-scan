static int cifs_readpage_worker(struct file *file, struct page *page, loff_t *poffset) {
    char *read_data;
    int rc;

    char *file_path = file_inode(file)->i_path;
    if (!allowed_path_characters(file_path)) {
        return -EINVAL;
    }

    file_path = normalize_path(file_path);

    read_data = kmap(page);
    //... rest of the code remains the same...
}

bool allowed_path_characters(const char *path) {
    while (*path) {
        if (!isalnum(*path) && *path != '.' && *path != '/') {
            return false;
        }
        path++;
    }
    return true;
}

char *normalize_path(char *path) {
    char *new_path = malloc(strlen(path) + 1);
    if (!new_path) {
        return NULL;
    }

    char *ptr = new_path;
    while (*path) {
        if (*path == '/' || *path == '.') {
            *ptr++ = *path;
        }
        path++;
    }
    *ptr = '\0';

    return new_path;
}