// Whitelist of allowed values for gpac_argc
enum {
    GPAC_ARGC_MIN = 0,
    GPAC_ARGC_MAX = 1024
};

u32 gf_sys_get_argc()
{
    // Check if gpac_argc is within the whitelist
    if (gpac_argc < GPAC_ARGC_MIN || gpac_argc > GPAC_ARGC_MAX) {
        return GPAC_ARGC_DEFAULT; // Return a default value
    }
    return gpac_argc;
}