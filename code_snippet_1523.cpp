static void ssh_queue_incoming_data(Ssh ssh,
				    const unsigned char **data, int *datalen)
{
    size_t len = *datalen;
    unsigned char *temp = malloc(len + 1); // +1 for null-termination
    if (!temp) {
        return; // handle error
    }

    memcpy(temp, *data, len < sizeof(temp)? len : sizeof(temp)); // restrict the copy to the valid buffer range
    temp[len] = '\0'; // null-terminate the temporary buffer

    bufchain_add(&ssh->queued_incoming_data, temp, len);
    free(temp);

    *data += len;
    *datalen = 0;
}