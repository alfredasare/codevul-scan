asmlinkage long compat_sys_recvfrom(int fd, void __user *buf, size_t len,
				    unsigned int flags, struct sockaddr __user *addr,
				    int __user *addrlen)
{
    size_t max_len = PAGE_SIZE; // assume a reasonable maximum buffer size
    if (len > max_len) {
        return -EMSGSIZE; // return an error if the length exceeds the maximum allowed
    }
    char* temp_buf = kmalloc(len, GFP_KERNEL); // allocate a temporary buffer
    if (!temp_buf)
        return -ENOMEM;
    int ret = sys_recvfrom(fd, temp_buf, len, flags | MSG_CMSG_COMPAT, addr, addrlen);
    if (ret >= 0)
        copy_to_user(buf, temp_buf, ret); // copy the received data to the user-space buffer
    kfree(temp_buf);
    return ret;
}