MagickExport const char *GetMagickVersion(size_t *version)
{
    char *versionBuffer = NULL;
    size_t bufferSize = 0;

    // Allocate a buffer with sufficient size
    bufferSize = strlen(MagickVersion) + 1;
    versionBuffer = malloc(bufferSize);

    if (versionBuffer!= NULL)
    {
        // Copy the version information into the buffer
        strcpy(versionBuffer, MagickVersion);

        // Store the buffer address in the version pointer
        *version = (size_t)versionBuffer;

        return versionBuffer;
    }
    else
    {
        return NULL; // Allocation failed
    }
}