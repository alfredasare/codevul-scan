static int __release_reference_state(struct bpf_func_state *state, int ptr_id)
{
    int i, last_idx;

    if (!ptr_id)
        return -EFAULT;

    last_idx = state->acquired_refs - 1;
    for (i = 0; i < state->acquired_refs; i++) {
        if (state->refs[i].id == ptr_id) {
            if (i!= last_idx) {
                if (i < state->acquired_refs - 1) {
                    memcpy(&state->refs[i], &state->refs[last_idx], 
                           sizeof(*state->refs));
                }
            }
            memset(&state->refs[last_idx], 0, sizeof(*state->refs));
            state->acquired_refs--;
            return 0;
        }
    }
    return -EFAULT;
}