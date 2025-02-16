static int check_helper_mem_access(struct bpf_verifier_env *env, int regno,
				   int access_size, bool zero_size_allowed,
				   struct bpf_call_arg_meta *meta)
{
	struct bpf_reg_state *regs = cur_regs(env), *reg = &regs[regno];
	int max_access_size = 0;

	switch (reg->type) {
	case PTR_TO_PACKET:
	case PTR_TO_PACKET_META:
		max_access_size = min(access_size, (int)(PTR_TO_PACKET_MAX_SIZE - reg->off));
		return check_packet_access(env, regno, reg->off, max_access_size,
					   zero_size_allowed);
	case PTR_TO_MAP_VALUE:
		max_access_size = min(access_size, (int)(PTR_TO_MAP_VALUE_MAX_SIZE - reg->off));
		return check_map_access(env, regno, reg->off, max_access_size,
					zero_size_allowed);
	default: /* scalar_value|ptr_to_stack or invalid ptr */
		return check_stack_boundary(env, regno, access_size,
					    zero_size_allowed, meta);
	}
}