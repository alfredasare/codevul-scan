void channel_free(channel_t *channel) {
    free(channel);
}

void channel_remove(u_int index) {
    if (channels[index] != NULL) {
        channel_free(channels[index]);
        channels[index] = NULL;
        channels_alloc--;
    }
}

void channel_close_all(void) {
    u_int i;

    for (i = 0; i < channels_alloc; i++) {
        if (channels[i] != NULL) {
            channel_close_fds(channels[i]);
            channel_remove(i);
            i--; // Decrement 'i' to account for removed element
        }
    }

    memset(channels, 0, sizeof(channels)); // Initialize channels array to zero
}