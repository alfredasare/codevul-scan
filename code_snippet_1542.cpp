void sequencer_init(void)
{
	if (sequencer_ok)
		return;
	size_t num_elements = SEQ_MAX_QUEUE;
	size_t element_size = EV_SZ;
	queue = vmalloc(num_elements * element_size);
	if (queue == NULL)
	{
		printk(KERN_ERR "sequencer: Can't allocate memory for sequencer output queue\n");
		return;
	}
	iqueue = vmalloc(num_elements * element_size);
	if (iqueue == NULL)
	{
		printk(KERN_ERR "sequencer: Can't allocate memory for sequencer input queue\n");
		vfree(queue);
		return;
	}
	sequencer_ok = 1;
}