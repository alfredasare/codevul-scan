c++
bool venc_dev::venc_set_meta_mode(bool mode)
{
    // Assuming there is a function called 'check_user_permission()' that returns true if the user is authorized
    if (!check_user_permission("modify_metadata_mode")) {
        return false;
    }

    metadatamode = mode;
    return true;
}