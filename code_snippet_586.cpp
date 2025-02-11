int sctp_register_af(struct sctp_af *af)
{
    enum {
        FAMILY_INET,
        FAMILY_INET6
    };

    if (af->sa_family < AF_INET || af->sa_family > AF_INET6) {
        return 0; // invalid family, return error
    }

    if (!allowed_families[af->sa_family - AF_INET]) {
        return 0; // family not allowed, return error
    }

    struct sctp_af *allowed_af = NULL;

    switch (af->sa_family) {
    case AF_INET:
        allowed_af = sctp_af_v4_specific;
        break;
    case AF_INET6:
        allowed_af = sctp_af_v6_specific;
        break;
    default:
        return 0; // unreachable
    }

    if (allowed_af) {
        list_head_init(&af->list);
        list_add_tail(&af->list, &sctp_address_families);
    } else {
        // handle error case
    }

    return 1;
}