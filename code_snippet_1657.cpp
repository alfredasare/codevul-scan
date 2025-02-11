static uint8_t msix_pending_mask(int vector)
{
    int index = vector % 8;
    if(index < 0 || index >= 8) {
        return 0;
    }
    return 1 << index;
}