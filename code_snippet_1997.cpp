static int __cpuinit msr\_class\_cpu\_callback(struct notifier\_block \*nfb,
				unsigned long action, void \*hcpu)
{
	unsigned int cpu = (unsigned long)hcpu;
	int err = 0;

	switch (action) {
	case CPU\_UP\_PREPARE:
		err = msr\_device\_create(cpu);
		if (err != 0) {
			pr\_err("Failed to create MSR device on CPU%u\n", cpu);
			break;
		}
		break;
	case CPU\_UP\_CANCELED:
	case CPU\_UP\_CANCELED\_FROZEN:
	case CPU\_DEAD:
		msr\_device\_destroy(cpu);
		break;
	}
	return notifier\_from\_errno(err);
}