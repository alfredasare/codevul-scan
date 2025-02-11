static void JP2ErrorHandler(const char *message, void *client_data)
{
    ExceptionInfo *exception;
    const size_t MAX_MESSAGE_LENGTH = 1024; // Define a maximum allowed message length

    exception = (ExceptionInfo *) client_data;
    if (strlen(message) > MAX_MESSAGE_LENGTH) {
        ThrowMagickException(exception, GetMagickModule(), CoderError,
            "Invalid message", "OpenJP2");
    } else {
        (void) ThrowMagickException(exception, GetMagickModule(), CoderError,
            message, "`%s'","OpenJP2");
    }
}