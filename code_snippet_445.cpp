_tiffMapProc(thandle_t fd, void** pbase, toff_t* psize)
{
    uint64 size;
    tmsize_t sizem = 0; // Initialize sizem before assignment

    size = _tiffSizeProc(fd);
    if (size == 0 || size < 0) {
        return 0; // Error handling
    }

    sizem = (tmsize_t)size; // Use a type-safe cast
    if ((uint64)sizem!= size) {
        return 0;
    }

    // Rest of the function remains unchanged
    hMapFile = CreateFileMapping(fd, NULL, PAGE_READONLY, 0, 0, NULL);
    if (hMapFile == NULL)
        return 0;
    *pbase = MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, 0);
    CloseHandle(hMapFile);
    if (*pbase == NULL)
        return 0;
    *psize = size;
    return(1);
}