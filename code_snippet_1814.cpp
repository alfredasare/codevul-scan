static uint8_t msix_pending_mask(int vector)
{
    if (vector >= 0 && vector <