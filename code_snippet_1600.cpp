void megaraid_sas_kill_hba(struct megasas_instance *instance)
{
    if (!capable(CAP_SYS_ADMIN))
        return;

    atomic_set(&instance->adprecovery, MEGASAS_HW_CRITICAL_ERROR);
   ...