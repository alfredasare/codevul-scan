void sched\_show\_task(struct task\_struct \*p)
{
 unsigned long free = 0;
 int ppid;
 unsigned state;

 state = p->state ? \_\_ffs(p->state) + 1 : 0;
 printk(KERN\_INFO "%-15.15s %c", p->comm,
 state < sizeof(stat\_nam) - 1 ? stat\_nam[state] : '?');
#if BITS\_PER\_LONG == 32
 if (state == TASK\_RUNNING)
 printk(KERN\_CONT " running ");
 else
 printk(KERN\_CONT " [MASKED] ");
#else
 if (state == TASK\_RUNNING)
 printk(KERN\_CONT " running task ");
 else
 printk(KERN\_CONT " [MASKED] ");
#endif
#ifdef CONFIG\_DEBUG\_STACK\_USAGE
 free = stack\_not\_used(p);
#endif
 rcu\_read\_lock();
 ppid = task\_pid\_nr(rcu\_dereference(p->real\_parent));
 rcu\_read\_unlock();
 printk(KERN\_CONT "%5lu %5d %6d [MASKED]\n", free,
 task\_pid\_nr(p), ppid);

 print\_worker\_info(KERN\_INFO, p);
 show\_stack(p, NULL);
}