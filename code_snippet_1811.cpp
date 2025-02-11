aiff_read_chanmap (SF_PRIVATE * psf, unsigned dword)
{
    const AIFF_CAF_CHANNEL_MAP * map_info ;
    unsigned channel_bitmap, channel_decriptions, bytesread ;
    int layout_tag ;
    char sanitized_input[256]; // Sanitized buffer for psf_binheader_readf

    // Validate layout_tag
    if (layout_tag < 0 || layout_tag > 255) {
        psf_log_printf (psf, "Invalid layout tag: %x\n", layout_tag);
        return 0;
    }

    // Restrict allowed values for layout_tag
    static const int allowed_layout_tags[] = {0, 1, 2, 3}; // Define allowed values here
    if (bsearch(&layout_tag, allowed_layout_tags, sizeof(allowed_layout_tags)/sizeof(allowed_layout_tags[0]), sizeof(int), compare_ints) == NULL) {
        psf_log_printf (psf, "Invalid layout tag: %x\n", layout_tag);
        return 0;
    }

    bytesread = psf_binheader_readf (psf, "444", &layout_tag, &channel_bitmap, &channel_decriptions) ;

    //... rest of the function...

    // Sanitize input for psf_binheader_readf
    if (bytesread < dword) {
        psf_binheader_readf (psf, "j", dword - bytesread, sanitized_input); // Pass sanitized input
    }

    //... rest of the function...
}