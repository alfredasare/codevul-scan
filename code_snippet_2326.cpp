void gf_sys_set_args(s32 argc, const char **argv)
{
#if !defined(__DARWIN__) && !defined(__APPLE__)
	if (!gpac_argc && (argc >= 0) && (argc <= sys_get_max_argv()) )
#endif
	{
		gpac_argc = (u32) argc;
		gpac_argv = argv;
	}
}

s32 sys_get_max_argv()
{
    return 1024;
}