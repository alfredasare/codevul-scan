mptcp_print(netdissect_options *ndo,
            const u_char *cp, u_int len, u_char flags)
{
    const struct mptcp_option *opt;
    u_int subtype;

    if (len < 3)
        return 0;

    opt = (const struct mptcp_option *) cp;

    /* Limit subtype to its valid range */
    subtype = MPTCP_OPT_SUBTYPE(opt->sub_etc);
    if (subtype > MPTCP_SUB_FCLOSE + 1) {
        subtype = MPTCP_SUB_FCLOSE + 1;
    }

    /* Check for integer overflow or wraparound */
    if (subtype > (MPTCP_SUB_FCLOSE + 1 - MPTCP_OPT_SUBTYPE(opt->sub_etc)) &&
        MPTCP_OPT_SUBTYPE(opt->sub_etc) != 0) {
        return 0;
    }

    ND_PRINT((ndo, " %s", mptcp_options[subtype].name));
    return mptcp_options[subtype].print(ndo, cp, len, flags);
}