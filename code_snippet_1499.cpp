otp_fini(krb5_context context, krb5_kdcpreauth_moddata moddata)
{
    if (moddata == NULL) {
        fprintf(stderr, "Error: moddata is NULL\n");
        return -1;
    }

    otp_state_free((otp_state *)moddata);
    return 0;
}