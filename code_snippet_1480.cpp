void r_pkcs7_free_certificaterevocationlists(RPKCS7CertificateRevocationLists *crls) {
    ut32 i;
    if (!crls) return;
    for (i = 0; i < crls->length; ++i) {
        if (crls->elements[i]) {
            r_x509_free_crl(crls->elements[i]);
            crls->elements[i] = NULL;
        }
    }
    R_FREE(crls->elements);
    crls->elements = NULL;
    R_FREE(crls);
}