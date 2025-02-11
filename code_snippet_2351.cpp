dtls1_hm_fragment_free(hm_fragment *frag)
{
    if (frag->msg_header.is_ccs)
    {
        if (frag->msg_header.saved_retransmit_state.enc_write_ctx != NULL)
            EVP_CIPHER_CTX_free(frag->msg_header.saved_retransmit_state.enc_write_ctx);
        if (frag->msg_header.saved_retransmit_state.write_hash != NULL)
            EVP_MD_CTX_destroy(frag->msg_header.saved_retransmit_state.write_hash);
    }
    if (frag->fragment != NULL)
        OPENSSL_free(frag->fragment);
    if (frag->reassembly != NULL)
        OPENSSL_free(frag->reassembly);
    if (frag != NULL)
        OPENSSL_free(frag);
}