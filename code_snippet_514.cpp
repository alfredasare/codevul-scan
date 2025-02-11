void nfc_llcp_free_sdp_tlv(struct nfc_llcp_sdp_tlv *sdp)
{
    if (!IS_ERR_OR_NULL(sdp) &&!IS_ERR_OR_NULL(sdp->tlv)) {
        kfree(sdp->tlv);
        kfree(sdp);
    } else {
        printk(KERN_ERR "Error: Invalid pointer to free.\n");
        return;
    }
}