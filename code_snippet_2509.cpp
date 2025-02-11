#define HANDLE_MIN 0u
#define HANDLE_MAX 255u
const uint16_t INVALID_HANDLE = 0xFFFF;

uint16_t AVRC_CloseBrowse(uint8_t handle) {
    // Validate the 'handle' input
    if (handle < HANDLE_MIN || handle > HANDLE_MAX) {
        // Return an error code or handle the invalid input as appropriate
        return INVALID_HANDLE;
    }
    return AVCT_RemoveBrowse(handle);
}