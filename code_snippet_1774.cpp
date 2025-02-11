dissect_fp_aal2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
    guint tvb_length = tvb_length(tvb);
    guint max_length = MAX_TVB_LENGTH;

    if (tvb_length > max_length) {
        return; // Handle invalid input
    }

    if (data && tvb_length + strlen((char*)data) > max_length) {
        return; // Handle invalid input
    }

    return dissect_fp_common(tvb, pinfo, tree, data);
}