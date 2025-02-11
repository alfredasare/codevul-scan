void sequencer_init(void)
{
    if (sequencer_ok)
        return;

    queue = vmalloc(SEQ_MAX_QUEUE * EV_SZ);
    if (queue == NULL)
    {
        printk(KERN_ERR "sequencer: Can't allocate memory for sequencer output queue\n");
        return;
    }

    iqueue = vmalloc(SEQ_MAX_QUEUE * IEV_SZ);
    if (iquue == NULL)
    {
        vfree(queue);
        queue = NULL;
        printk(KERN_ERR "sequencer: Can't allocate memory for sequencer input queue\n");
        return;
    }

    queue->head = 0;
    queue->tail = 0;
    iqueue->head = 0;
    iqueue->tail = 0;

    sequencer_ok = 1;
}