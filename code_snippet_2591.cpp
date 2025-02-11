ospf6_print_ls_type(netdissect_options *ndo,
                    register u_int ls_type, register const rtrid_t *ls_stateid)
{
    // Validate ls_type before using it in the tok2str function calls
    if (ls_type >= OSPF6_LSA_MAX) {
        fprintf(stderr, "Invalid ls_type value: %u\n", ls_type);
        return;
    }

    ND_PRINT((ndo, "\n\t    %s LSA (%d), %s Scope%s, LSA-ID %s",
           tok2str(ospf6_lsa_values, "Unknown", ls_type),
           ls_type,
           tok2str(ospf6_ls_scope_values, "Unknown", ls_type),
           ls_type & 0x8000 ? ", transitive" : "",
           ipaddr_string(ndo, ls_stateid)));
}