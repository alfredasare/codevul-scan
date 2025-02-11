void ga_enable_logging(GAState *s)
{
    try {
        s->logging_enabled = true;
    } catch (Exception& e) {
        Log::error("Error enabling logging: " + e.what());
        throw; // Rethrow the exception to allow it to be handled elsewhere in the application
    }
}