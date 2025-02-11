void smp_proc_master_id(tSMP_CB* p_cb, tSMP_INT_DATA* p_data) {
   ...
    STREAM_TO_UINT16_safe(&le_key.ediv, p); // Use safe integer arithmetic function
   ...
}

// Define the safe integer arithmetic function
uint16_t STREAM_TO_UINT16_safe(uint16_t* dst, uint8_t* src) {
    uint16_t result = 0;
    int16_t shift = 0;
    while (*src!= 0 && shift < 16) {
        result |= (*src & 0x1) << shift;
        src++;
        shift++;
    }
    return result;
}