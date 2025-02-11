void rsvp_clear_checksum(void *header)
{
    struct rsvp_common_header *rsvp_com_header = (struct rsvp_common_header *) header;

    if (header == NULL || rsvp_com_header == NULL) {
        return; // or throw an error
    }

    uint16_t calculated_checksum = calculate_checksum((const char *)rsvp_com_header, sizeof(*rsvp_com_header));
    rsvp_com_header->checksum[0] = (calculated_checksum >> 8) & 0xFF;
    rsvp_com_header->checksum[1] = calculated_checksum & 0xFF;
}