void out_pkt_free(pkt_t* pkt)
{
    if (!pkt) {
        return; // Check for null pointer
    }

    nad_free(pkt->nad);
    jid_free(pkt->from);
    jid_free(pkt->to);

    // Use a safe memory allocation function
    safe_free(pkt);
}