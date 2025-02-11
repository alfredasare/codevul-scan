void start_thread_common(struct pt_regs *regs, u32 new_ip, u32 new_sp, int cs, u32 ds, u32 ss)
{
    //... (rest of the function remains unchanged)

    if (!test_thread_flag(TIF_X32)) {
        // Return an error code instead of an error message
        return -EOPNOTSUPP;
    }
}

void start_thread_ia32(struct pt_regs *regs, u32 new_ip, u32 new_sp)
{
    int err = start_thread_common(regs, new_ip, new_sp,
                                  test_thread_flag(TIF_X32)? __USER_CS : __USER32_CS,
                                  __USER_DS, __USER_DS);

    if (err < 0) {
        // Handle the error code securely
        printk(KERN_ERR "Error: %d\n", err);
    } else {
        // Continue with thread creation
    }
}