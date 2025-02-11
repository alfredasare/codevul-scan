power\_pmu\_notifier(struct notifier\_block \*self, unsigned long action, void \*hcpu)
{
 static unsigned int cpu;

 cpu = (long)hcpu;

 switch (action & ~CPU\_TASKS\_FROZEN) {
 case CPU\_UP\_PREPARE:
 power\_pmu\_setup(cpu);
 break;

 default:
 break;
 }

 return NOTIFY\_OK;
}