static u64 dccp_ack_seq(const struct dccp_hdr *dh)
{
    const struct dccp_hdr_ack_bits *dhack;

    // Validate input data
    if ((void *)dh + __dccp_basic_hdr_len(dh) > (void *)dh + sizeof(*dh)) {
        return 0; // or handle the error as needed
    }

    // Calculate the offset safely
    size_t offset = __dccp_basic_hdr_len(dh);
    dhack = (void *)dh + offset;

    return ((u64)ntohs(dhack->dccph_ack_nr_high) << 32) +
           ntohl(dhack->dccph_ack_nr_low);
}