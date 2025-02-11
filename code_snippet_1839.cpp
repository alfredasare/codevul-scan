int log_host_states(int type, time_t *timestamp) {
    char temp_buffer[4096]; // Allocate a fixed size buffer
    host *temp_host = NULL;

    if(type == INITIAL_STATES && log_initial_states == FALSE)
        return OK;

    for(temp_host = host_list; temp_host != NULL; temp_host = temp_host->next) {

        snprintf(temp_buffer, sizeof(temp_buffer), "%s HOST STATE: %s;%s;%s;%d;%s\n",
                 (type == INITIAL_STATES) ? "INITIAL" : "CURRENT",
                 temp_host->name,
                 host_state_name(temp_host->current_state),
                 state_type_name(temp_host->state_type),
                 temp_host->current_attempt,
                 (temp_host->plugin_output == NULL) ? "" : temp_host->plugin_output);

        write_to_all_logs_with_timestamp(temp_buffer, NSLOG_INFO_MESSAGE, timestamp);
    }

    return OK;
}