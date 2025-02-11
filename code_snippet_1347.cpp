void rds_inc_info_copy(struct rds_incoming *inc,
		       struct rds_info_iterator *iter,
		       __be32 saddr, __be32 daddr, int flip)
{
    struct rds_info_message minfo;

    minfo.seq = be64_to_cpu(inc->i_hdr.h_sequence);
    minfo.len = be32_to_cpu(inc->i_hdr.h_len);
    minfo.tos = inc->i_conn->c_tos;

    if (flip) {
        minfo.laddr = daddr;
        minfo.faddr = saddr;
        minfo.lport = inc->i_hdr.h_dport;
        minfo.fport = inc->i_hdr.h_sport;
    } else {
        minfo.laddr = saddr;
        minfo.faddr = daddr;
        minfo.lport = inc->i_hdr.h_sport;
        minfo.fport = inc->i_hdr.h_dport;
    }

    // Clear or mask sensitive fields
    minfo.lport = 0;
    minfo.fport = 0;
    minfo.laddr = 0;
    minfo.faddr = 0;

    minfo.flags = 0;

    rds_info_copy(iter, &minfo, sizeof(minfo));
}