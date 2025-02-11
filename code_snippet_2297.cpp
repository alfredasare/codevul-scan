bool xmp_files_close(XmpFilePtr xf, XmpCloseFileOptions options)
{
    CHECK_PTR(xf, false);
    RESET_ERROR;
    try {
        auto txf = reinterpret_cast<SXMPFiles *>(xf);
        txf->CloseFile(options);
    }
    catch (const XMP_Error &e) {
        set_error(e);
        try {
            txf->CloseFile(options); // Re-close the file to ensure it's properly closed
        }
        catch (...) {
            // Ignore any additional exceptions
        }
        return false;
    }
    finally {
        if (txf) {
            txf->CloseFile(options); // Close the file
            txf->RemoveTemporaryFile(); // Remove the temporary file
        }
    }
    return true;
}