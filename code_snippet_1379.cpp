static OPJ_BOOL bmp_read_raw_data(FILE* IN, const char* filePath, OPJ_UINT32 stride,
                                  OPJ_UINT32 width, OPJ_UINT32 height)
{
    // Validate the file path
    const char* allowedDirs[] = {"/path/to/allowed/directory"};
    for (const char** dir = allowedDirs; *dir; ++dir) {
        if (strncmp(filePath, *dir, strlen(*dir)) == 0 && filePath[strlen(*dir)] == '/') {
            break;
        }
    }
    if (*dir == NULL) {
        fprintf(stderr, "Unauthorized file access\n");
        return OPJ_FALSE;
    }

    OPJ_UINT8* pData = malloc(stride * height * sizeof(OPJ_UINT8));
    if (fread(pData, sizeof(OPJ_UINT8), stride * height, IN)!= (stride * height)) {
        free(pData);
        fprintf(stderr, "Error reading file\n");
        return OPJ_FALSE;
    }
    free(pData);
    return OPJ_TRUE;
}