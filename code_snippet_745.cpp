static int check_helper_mem_access(struct bpf_verifier_env *env, int regno,
				   int access_size, bool zero_size_allowed,
				   struct bpf_call_arg_meta *meta)
{
	struct bpf_reg_state *regs = cur_regs(env), *reg = &regs[regno];

	if (regno < 0 || regno >= env->num_registers) {
		return -EINVAL;
	}

	if (access_size <= 0 || access_size > BPF_REG_SIZE) {
		return -EINVAL;
	}

	switch (reg->type) {
	case PTR_TO_PACKET:
	case PTR_TO_PACKET_META:
		return check_packet_access(env, regno, reg->off, access_size,
					   zero_size_allowed);
	case PTR_TO_MAP_VALUE:
		return check_map_access(env, regno, reg->off, access_size,
					zero_size_allowed);
	default: /* scalar_value|ptr_to_stack or invalid ptr */
		if (!reg) {
			return -EFAULT; // Null pointer dereference
		}
		return check_stack_boundary(env, regno, access_size,
					    zero_size_allowed, meta);
	}
}