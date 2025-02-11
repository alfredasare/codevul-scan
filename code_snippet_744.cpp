static inline int red_channel_client_urgent_marshaller_is_active(RedChannelClient *rcc)
{
    pthread_mutex_lock(&rcc->send_data.mutex);
    int result = (rcc->send_data.marshaller == rcc->send_data.urgent.marshaller);
    pthread_mutex_unlock(&rcc->send_data.mutex);

    return result;
}

pthread_mutex_init(&rcc->send_data.mutex, NULL);

...

pthread_mutex_destroy(&rcc->send_data.mutex);