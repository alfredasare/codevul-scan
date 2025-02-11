exp_build_l4proto_sctp(const struct nf_conntrack *ct, struct nethdr *n, int a)
{
    char buffer[sizeof(struct nfct_attr_grp_port) + 1]; // Add one extra byte for null termination
    //... (rest of the function)

    // Properly null-terminate the buffer
    buffer[sizeof(buffer) - 1] = '\0';

    ct_build_group(ct, ATTR_GRP_ORIG_PORT, n, a, buffer);
}