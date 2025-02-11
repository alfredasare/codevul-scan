int ssl3_num_ciphers(const SSL\_METHOD \*meth)
{
    return (meth->ssl3_enc->num_ciphers);
}