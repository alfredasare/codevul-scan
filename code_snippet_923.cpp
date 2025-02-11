void sched_show_task(struct task_struct *p)
{
    unsigned long free = 0;
    int ppid;
    unsigned state;

    state = p->state? __ffs(p->state) + 1 : 0;
    printk(KERN_INFO "%-15.15s %c", p->comm,
        state < sizeof(stat_nam) - 1? stat_nam[state] : '?');
    #if BITS_PER_LONG == 32
    if (state!= TASK_RUNNING)
        printk(KERN_CONT " %08lx ", thread_saved_pc(p) & 0xffffffff);
    #else
    if (state!= TASK_RUNNING)
        printk(KERN_CONT " %016lx ", thread_saved_pc(p) & 0xffffffffffffffff);
    #endif
   ...