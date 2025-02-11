int rsvp_clear_checksum(void *header)
{
    struct rsvp_common_header *rsvp_com_header = (struct rsvp_common_header *) header;

    if (rsvp_com_header->checksum_length < sizeof(rsvp_com_header->checksum)) {
        return -1;
    }

    memset(rsvp_com_header->checksum, 0, sizeof(rsvp_com_header->checksum));
    return 0;
}

struct rsvp_common_header {
    // Other fields
    uint8_t checksum[16];
    int checksum_length;
};