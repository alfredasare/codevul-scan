static void default_idle(void)
{
	if (arm_pm_idle)
		arm_pm_idle();
	else
		cpu_do_idle();

	/* Fix for CWE-264, CVE-2014-987