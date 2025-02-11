int flush_old_exec(struct linux_binprm * bprm)
{
    int retval;

    //...

    if (!bprm->mm ||!bprm->mm->mmap ||!bprm->file ||!bprm->file->f_op) {
        printk(KERN_ERR "Invalid bprm->mm or bprm->file\n");
        return -EINVAL;
    }

    //...
}