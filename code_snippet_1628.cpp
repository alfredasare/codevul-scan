static int __release_reference_state(struct bpf_func_state *state, int ptr_id)
{
	int i;

	if (!ptr_id || ptr_id >= state->acquired_refs || state->acquired_refs <= 0)
		return -EFAULT;

	memset(&state->refs[ptr_id], 0, sizeof(state->refs[ptr_id]));
	state->acquired_refs--;

	for (i = ptr_id; i < state->acquired_refs; i++)
		state->refs[i] = state->refs[i + 1];

	return 0;
}