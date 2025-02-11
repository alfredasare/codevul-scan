#define MAX_BUFFER_SIZE 1024

static void ssh_queue_incoming_data(Ssh ssh,
				    const unsigned char **data, int *datalen)
{
    // Check if the new datalen value exceeds the maximum buffer size
    if (*datalen > MAX_BUFFER_SIZE - bufchain_get_length(&ssh->queued_incoming_data)) {
        // Return an error, log the event, or handle it appropriately
        return;
    }

    bufchain_add(&ssh->queued_incoming_data, *data, *datalen);
    *data += *datalen;
    *datalen = 0;
}