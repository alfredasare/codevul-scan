otp_fini(krb5_context context, krb5_kdcpreauth_moddata moddata)
{
    otp_state *state = (otp_state *)moddata;
    free(state);
}