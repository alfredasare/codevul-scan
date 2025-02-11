_tiffMapProc(thandle_t fd, void** pbase, toff_t* psize)
{
	uint64_t size;
	tmsize_t sizem;
	HANDLE hMapFile;

	size = _tiffSizeProc(fd);

	// Check if size is within the range of tmsize_t
	if (size > static_cast<uint64_t>(std::numeric_limits<tmsize_t>::max()) || size < static_cast<uint64_t>(std::numeric_limits<tmsize_t>::min())) {
		return 0;
	}

	sizem = (tmsize_t)size;

	if ((uint64_t)sizem != size) {
		return 0;
	}

	hMapFile = CreateFileMapping(fd, NULL, PAGE_READONLY, 0, 0, NULL);
	if (hMapFile == NULL) {
		return 0;
	}
	*pbase = MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, 0);
	CloseHandle(hMapFile);
	if (*pbase == NULL) {
		return 0;
	}
	*psize = size;
	return 1;
}