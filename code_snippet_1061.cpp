void _WM_do_meta_text(struct _mdi *mdi, struct _event_data *data) {
    //...

    if (mdi->extra_info.mixer_options & WM_MO_TEXTASLYRIC) {
        // Sanitize and validate the input data
        char *sanitized_string = sanitize_string(data->data.string);
        if (sanitized_string!= NULL) {
            mdi->lyric = sanitized_string;
            free(sanitized_string);  // Free the allocated memory
        }
    }

    return;
}

char *sanitize_string(const char *input) {
    char *output = NULL;
    size_t output_len = 0;

    const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
    for (size_t i = 0; input[i]!= '\0'; i++) {
        if (strchr(allowed_chars, input[i])!= NULL) {
            output_len++;
        }
    }

    output = malloc(output_len + 1);
    if (output!= NULL) {
        size_t j = 0;
        for (size_t i = 0; input[i]!= '\0'; i++) {
            if (strchr(allowed_chars, input[i])!= NULL) {
                output[j++] = input[i];
            }
        }
        output[output_len] = '\0';
    }

    return output;
}