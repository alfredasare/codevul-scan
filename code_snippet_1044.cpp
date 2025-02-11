static void default_idle(void)
{
    if (arm_pm_idle)
        arm_pm_idle();
    else
    {
        size_t input_size = strlen(cpu_do_idle_input);
        if (input_size <= CPU_DO_IDLE_MAX_SIZE)
            cpu_do_idle(cpu_do_idle_input, input_size);
        else
            // Handle error or truncate input data
    }
    local_irq_enable();
}