static void btif_read_le_key(const uint8_t key_type, const size_t key_len, bt_bdaddr_t bd_addr,
 const uint8_t addr_type, const bool add_key, bool *device_added, bool *key_found)
{
    assert(device_added);
    assert(key_found);

    char buffer[100]; // Define a fixed buffer size
    memset(buffer, 0, sizeof(buffer));

    if (key_len > sizeof(buffer)) {
        // Handle error condition or return an error code
        return;
    }

    // Rest of the function remains the same
}