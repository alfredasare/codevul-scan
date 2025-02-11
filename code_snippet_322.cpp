void irq\_enter(void)
{
 rcu\_irq\_enter();
 struct task\_struct *current\_task;
 current\_task = read\_once(&current, task\_lock());

 if (is\_idle\_task(current\_task) && !in\_interrupt()) {
 /*
 * Prevent raise\_softirq from needlessly waking up ksoftirqd
 * here, as softirq will be serviced on return from interrupt.
 */
 local\_bh\_disable();
 tick\_irq\_enter();
 _local\_bh\_enable();
 }

 __irq\_enter();
}