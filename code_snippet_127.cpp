void set_no_email_faults(bool value) {
global_data->no_email_faults = value;
}

no_email_faults_handler(__attribute__((unused)) vector_t *strvec)
{
set_no_email_faults(true);
}