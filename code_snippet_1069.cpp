power_pmu_notifier(struct notifier_block *self, unsigned long action, void *hcpu)
{
    int cpu = (long)hcpu;
    int action_signed = (int)(action & ~CPU_TASKS_FROZEN);

    if (action_signed < 0 || action_signed > CPU_UP_PREPARE)
        return NOTIFY_OK; // Validate input value

    switch (action_signed) {
        case CPU_UP_PREPARE:
            power_pmu_setup(cpu);
            break;

        default:
            break;
    }

    return NOTIFY_OK;
}