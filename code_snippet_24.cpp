asmlinkage long sys_oabi_socketcall(int call, unsigned long __user *args)
{
    unsigned long r = -EFAULT, a[6];

    switch (call) {
        case SYS_BIND:
        case SYS_CONNECT:
        case SYS_SENDMSG:
            if (copy_from_user(a, args, (call == SYS_SENDMSG)? 3 * sizeof(long) : sizeof(long)) == 0) {
                //...
            }
            break;
        case SYS_SENDTO:
            if (copy_from_user(a, args, 6 * sizeof(long)) == 0) {
                //...
            }
            break;
        default:
            r = sys_socketcall(call, args);
    }

    return r;
}