int log_host_states(int type, time_t *timestamp) {
    char *temp_buffer = NULL;
    host *temp_host = NULL;;

    /* bail if we shouldn't be logging initial states */
    if(type == INITIAL_STATES && log_initial_states == FALSE)
        return OK;

    for(temp_host = host_list; temp_host!= NULL; temp_host = temp_host->next) {
        char *err_str = NULL;
        size_t err_len = 0;

        if((err_str = malloc(1024)) == NULL) {
            fprintf(stderr, "Error allocating memory: %s\n", strerror(errno));
            free(err_str);
            continue;
        }

        if(asprintf(&temp_buffer, "%s HOST STATE: %s;%s;%s;%d;%s\n", (type == INITIAL_STATES)? "INITIAL" : "CURRENT",
                        temp_host->name,
                        host_state_name(temp_host->current_state),
                        state_type_name(temp_host->state_type),
                        temp_host->current_attempt,
                        (temp_host->plugin_output == NULL)? "" : temp_host->plugin_output) < 0) {
            fprintf(stderr, "Error formatting string: %s\n", strerror(errno));
            free(err_str);
            free(temp_buffer);
            continue;
        }

        write_to_all_logs_with_timestamp(temp_buffer, NSLOG_INFO_MESSAGE, timestamp);
        free(temp_buffer);
        free(err_str);
    }

    return OK;
}