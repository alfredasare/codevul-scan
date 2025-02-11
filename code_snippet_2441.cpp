uint8_t *faad_getbitbuffer(bitfile *ld, uint32_t bits DEBUGDEC)
{
    int i;
    unsigned int temp;
    int bytes = bits >> 3; // Calculate the number of bytes
    int remainder = bits & 0x7; // Calculate the remaining bits

    if (bits > 8 * sizeof(uint8_t)) { // Check if bits exceed maximum allowed
        return NULL; // Return error or handle invalid input
    }

    if (bytes * 8 != bits) { // Check if bits are not a multiple of 8
        return NULL; // Return error or handle invalid input
    }

    uint8_t *buffer = (uint8_t*)faad_malloc((bytes+1)*sizeof(uint8_t)); // Allocate memory for the buffer

    for (i = 0; i < bytes; i++) {
        buffer[i] = (uint8_t)faad_getbits(ld, 8 DEBUGVAR(print,var,dbg)); // Read 8 bits at a time
    }

    if (remainder) {
        temp = faad_getbits(ld, remainder DEBUGVAR(print,var,dbg)) << (8-remainder);
        buffer[bytes] = (uint8_t)temp; // Store the remaining bits
    }

    // Copy the buffer contents to a new location
    uint8_t* new_buffer = (uint8_t*)malloc((bytes+1)*sizeof(uint8_t));
    memcpy(new_buffer, buffer, bytes+1);

    free(buffer); // Free the original buffer
    return new_buffer; // Return the new buffer
}