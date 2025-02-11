getu16(int swap, uint16_t value)
{
    uint16_t result = value;

    if (swap) {
        // Use bitwise operation to swap the bytes
        result = (result << 8) | (result >> 8);
    }

    return result;
}