opj_bool pi_next(opj_pi_iterator_t * pi)
{
    switch (pi->poc.prg) {
    case LRCP:
        return pi_next_lrcp(pi);
    case RLCP:
        return pi_next_rlcp(pi);
    case RPCL:
        return pi_next_rpcl(pi);
    case PCRL:
        return pi_next_pcrl(pi);
    case CPRL:
        return pi_next_cprl(pi);
    case PROG_UNKNOWN:
        return OPJ_FALSE;
    }

    return OPJ_FALSE;
}

opj_bool pi_next_lrcp(opj_pi_iterator_t* pi)
{
    opj_tcp_t* tcp = NULL;
    opj_tcd_tile_t* tile = NULL;
    opj_tcd_layer_t* layer = NULL;
    opj_tcd_component_t* tilecomp = NULL;
    int i, index;

    if (pi->index >= pi->poc.nb_comps)
        return OPJ_FALSE;

    index = pi->index;
    tilecomp = pi->tilecomp + index;

    // Check if index is within bounds
    if (index < 0 || index >= pi->poc.nb_comps || tilecomp->data == NULL)
        return OPJ_FALSE;

    // ... rest of the original function
}