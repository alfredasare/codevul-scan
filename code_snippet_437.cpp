bool venc_dev::venc_set_meta_mode(bool mode)
{
    if (!isValidMetadataMode(mode)) {
        // Return an error message indicating an invalid metadata mode
        return false;
    }
    metadatamode = mode;
    return true;
}

bool venc_dev::isValidMetadataMode(bool mode)
{
    // Check if the metadata mode is within a valid range or meets certain criteria
    //...
    return true; // or false depending on the validation result
}