void nfc_llcp_free_sdp_tlv(struct nfc_llcp_sdp_tlv *sdp)
{
	if (sdp && sdp->tlv) {
		kfree(sdp->tlv);
	}
	kfree(sdp);
}