static int handle_xrstors(struct kvm_vcpu *vcpu)
{
    const char *input = vcpu->input; // assume vcpu->input contains the input string
    size_t input_len = strlen(input);

    // Validate the input
    if (input_len > MAX_INPUT_LENGTH || strcasecmp(input, "allowed-input")!= 0) {
        WARN(1, "Invalid input: %s", input);
        return -1;
    }

    skip_emulated_instruction(vcpu, input);

    return 1;
}