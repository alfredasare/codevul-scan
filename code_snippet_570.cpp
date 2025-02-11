static const char* inspectorFilesBasePath()
{
    const gchar* environmentPath = g_getenv("WEBKIT_INSPECTOR_PATH");
    if (environmentPath && g_file_test(environmentPath, G_FILE_TEST_IS_DIR))
        return environmentPath;

    gchar* sanitizedInspectorFilesPath = g_strdup_printf("%s/%s%s",
                                                      g_path_get_dirname(DATA_DIR),
                                                      WEBKITGTK_API_VERSION_STRING,
                                                      G_DIR_SEPARATOR_S "webinspector");
    return sanitizedInspectorFilesPath;
}