if (item_len < sizeof(cert)) {
    ND_PRINT((ndo, " [|%s]", NPSTR(ISAKMP_NPTYPE_CERT)));
    return NULL;
}
memcpy(&cert, ext, sizeof(cert));