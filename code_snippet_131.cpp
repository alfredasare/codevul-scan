static void perf_mmap_open(struct vm_area_struct *vma)
{
    struct perf_event *event = vma->vm_file->private_data;

    if (vma && vma->vm_file && vma->vm_file->fops && vma->vm_file->fops->permission) {
        if (!vma->vm_file->fops->permission(vma->vm_file, FMODE_READ)) {
            printk(KERN_ERR "Permission denied\n");
            return;
        }
    }

    atomic_inc(&event->mmap_count);
}