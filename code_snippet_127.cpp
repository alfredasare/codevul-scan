no_email_faults_handler(__attribute__((unused)) vector_t *strvec)
{
    try {
        global_data->no_email_faults = true;
    } catch (const std::exception& e) {
        log_error("Error setting no email faults: %s", e.what());
    }
}