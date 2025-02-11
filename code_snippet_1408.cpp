u32 hid_field_extract(const struct hid_device *hid, u8 *report,
                     unsigned offset, unsigned n)
{
    if (n > 32) {
        hid_warn(hid, "hid_field_extract() called with n (%d) > 32! (%s)\n",
                 n, current->comm);
        n = 32; // cap at 32
    } else if (n < 1) {
        hid_warn(hid, "hid_field_extract() called with n (%d) < 1! (%s)\n",
                 n, current->comm);
        return 0; // return 0 on invalid input
    }

    return __extract(report, offset, n);
}