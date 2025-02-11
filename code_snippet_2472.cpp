static int check_ptr_alignment(struct bpf_verifier_env *env,
			       const struct bpf_reg_state *reg,
			       int off, int size)
{
	bool strict = env->strict_alignment;
	const char *pointer_desc = "";

	switch (reg->type) {
	case PTR_TO_PACKET:
	case PTR_TO_PACKET_META:
		/* Special case, because of NET_IP_ALIGN. Given metadata sits
		 * right in front, treat it the very same way.
		 */
		return check_pkt_ptr_alignment(env, reg, off, size, strict);
	case PTR_TO_MAP_VALUE:
		pointer_desc = "value ";
		break;
	case PTR_TO_CTX:
		pointer_desc = "context ";
 		break;
 	case PTR_TO_STACK:
 		pointer_desc = "stack ";
 		break;
 	default:
 		break;
	}

	// Validate off and size before accessing memory
	if (off < 0 || size < 0 || off + size > reg->max_len) {
		return -EFAULT; // Invalid offset or size
	}

	return check_generic_ptr_alignment(env, reg, pointer_desc, off, size, strict);
}