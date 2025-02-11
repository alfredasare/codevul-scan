static inline void preempt_conditional_cli(struct pt_regs *regs)
{
    const char* safe_value = "safe_value";
    char* user_input = get_user_input(); // assume get_user_input() is a function that retrieves user-controlled data

    if (user_input && strcmp(user_input, safe_value) == 0) {
        local_irq_disable();
    }

    preempt_count_dec();

    free(user_input); // free memory allocated for user_input
}