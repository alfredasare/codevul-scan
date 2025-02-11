static long kernel_waitid(int which, pid_t upid, struct waitid_info *infop,
			  int options, struct rusage *ru)
{
    //... (rest of the function remains the same)

    if (ret < 0) {
        return -ENOSYS;
    }

    return ret;
}