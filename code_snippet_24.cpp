asmlinkage long sys_oabi_socketcall(int call, unsigned long __user *args)
{
	unsigned long r = -EFAULT;
	size_t argsize;
	unsigned long a[6];

	switch (call) {
	case SYS_BIND:
		argsize = 3 * sizeof(long);
		break;
	case SYS_CONNECT:
		argsize = 3 * sizeof(long);
		break;
	case SYS_SENDTO:
		argsize = 6 * sizeof(long);
		break;
	case SYS_SENDMSG:
		argsize = 3 * sizeof(long);
		break;
	default:
		argsize = 0;
		break;
	}

	if (copy_from_user(a, args, argsize) == 0)
		switch (call) {
		case SYS_BIND:
			r = sys_oabi_bind(a[0], (struct sockaddr __user *)a[1], a[2]);
			break;
		case SYS_CONNECT:
			r = sys_oabi_connect(a[0], (struct sockaddr __user *)a[1], a[2]);
			break;
		case SYS_SENDTO:
			r = sys_oabi_sendto(a[0], (void __user *)a[1], a[2], a[3],
					    (struct sockaddr __user *)a[4], a[5]);
			break;
		case SYS_SENDMSG:
			r = sys_oabi_sendmsg(a[0], (struct user_msghdr __user *)a[1], a[2]);
			break;
		default:
			r = sys_socketcall(call, args);
		}

	return r;
}