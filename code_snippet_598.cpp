static inline int red_channel_client_urgent_marshaller_is_active(RedChannelClient *rcc)
{
    const char *expected_marshaller = "urgent";
    return (strcmp(rcc->send_data.marshaller, expected_marshaller) == 0);
}