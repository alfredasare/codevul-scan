opj_bool pi_next(opj_pi_iterator_t * pi)
{
    if (pi->poc.prg == LRCP) {
        return pi_next_lrcp(pi);
    } else if (pi->poc.prg == RLCP) {
        return pi_next_rlcp(pi);
    } else if (pi->poc.prg == RPCL) {
        return pi_next_rpcl(pi);
    } else if (pi->poc.prg == PCRL) {
        return pi_next_pcrl(pi);
    } else if (pi->poc.prg == CPRL) {
        return pi_next_cprl(pi);
    } else {
        return OPJ_FALSE; // Return a valid value for unknown cases
    }
}