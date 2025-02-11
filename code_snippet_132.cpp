static void perf_mmap_open(struct vm_area_struct *vma)
{
	struct perf_event *event = vma->vm_file->private_data;
}

void perf_event__put(struct perf_event *event)
{
	if (atomic_dec_and_test(&event->mmap_count)) {
		perf_event__destroy(event);
	}
}