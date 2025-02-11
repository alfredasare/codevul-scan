static int libz_initialized = 0;

static void _initialize_libz(void) {
    if (!libz_initialized && gdImageLibraryInit() == 0) {
        gd_error("GD2 support is not available - no libz\n");
        return;
    }
    libz_initialized = 1;
}

static void _noLibzError(void) {
    _initialize_libz();

    // Other initialization code here

    if (libz_initialized && gdImageLibraryTerm() == 0) {
        gd_error("Failed to release GD2 resources\n");
    }
}