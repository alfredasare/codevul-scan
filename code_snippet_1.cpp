gs_main_run_file_open(gs_main_instance * minst, const char *file_name, ref * pfref)
{
    gs_main_set_lib_paths(minst);
    size_t len = strlen(file_name) + 1;
    char *buffer = gs_main_malloc(len); // Allocate enough memory for the file name
    if (buffer == NULL) {
        emprintf1(minst->heap, "Memory allocation failed.\n");
        return_error(gs_error_Fatal);
    }
    memcpy(buffer, file_name, len); // Copy the file name into the allocated buffer
    if (gs_main_lib_open(minst, buffer, pfref) < 0) {
        emprintf1(minst->heap, "Can't find initialization file %s.\n", buffer);
        gs_main_free(buffer); // Free the allocated memory
        return_error(gs_error_Fatal);
    }
    r_set_attrs(pfref, a_execute + a_executable);
    gs_main_free(buffer); // Free the allocated memory
    return 0;
}