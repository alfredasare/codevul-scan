static const char* inspectorFilesBasePath()
{
    const gchar* environmentPath = g_getenv("WEBKIT_INSPECTOR_PATH");

    if (environmentPath && g_str_has_prefix(environmentPath, "..") && g_file_test(environmentPath, G_FILE_TEST_IS_DIR))
    {
        g_printerr("Error: Directory traversal pattern detected in environment variable\n");
        return NULL;
    }

    const gchar* validatedPath = g_environ_get_value("WEBKIT_INSPECTOR_PATH", environmentPath);

    if (validatedPath && g_file_test(validatedPath, G_FILE_TEST_IS_DIR))
        return validatedPath;

    static const char* inspectorFilesPath = DATA_DIR""G_DIR_SEPARATOR_S
                                            "webkitgtk-"WEBKITGTK_API_VERSION_STRING""G_DIR_SEPARATOR_S
                                            "webinspector"G_DIR_SEPARATOR_S;
    return inspectorFilesPath;
}