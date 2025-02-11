static bool should_load_proto(struct iptables_command_state *cs)
{
    if (!cs || !cs->protocol)
        return false;

    if (cs->protocol[0] == '\0')
        return false;

    if (find_proto(cs->protocol, XTF_DONT_LOAD,
            cs->options & OPT_NUMERIC, NULL) == NULL)
        return true;
    return !cs->proto_used;
}