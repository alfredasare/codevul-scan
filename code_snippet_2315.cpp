GF_Err gf_isom_avc_set_inband_config(GF_ISOFile *the_file, u32 trackNumber, u32 DescriptionIndex)
{
    // Validate DescriptionIndex
    if (DescriptionIndex < 0 || DescriptionIndex > MAX_DESCRIPTION_INDEX) {
        return GF_ERR_INVALID_INPUT;
    }

    // Sanitize DescriptionIndex
    DescriptionIndex = sanitize_u32(DescriptionIndex);

    return gf_isom_avc_config_update_ex(the_file, trackNumber, DescriptionIndex, NULL, 3);
}

u32 sanitize_u32(u32 value) {
    if (value >= 0 && value <= 3) {
        return value;
    }
    return 0; // Default to a safe value if not found in the whitelist
}