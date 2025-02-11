static void _noLibzError (void)
{
    // Check if the user has the necessary permissions and credentials
    if (hasPermissionToAccessGD2Support()) {
        gd_error("GD2 support is not available");
    } else {
        // Log the error instead of exposing sensitive information
        logError("GD2 support is not available");
    }
}