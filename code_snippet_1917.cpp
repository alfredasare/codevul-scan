#define MAX_TVB_SIZE 1024 * 1024 // Set a maximum size for tvb (e.g., 1 MB)

dissect_fp_aal2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
    if (tvb_captured_length(tvb) > MAX_TVB_SIZE) {
        return NULL;
    }

    return dissect_fp_common(tvb, pinfo, tree, data);
}