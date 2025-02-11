u32 gf_sys_get\_argc()
{
#ifdef WIN32
if (gpac\_argc > UINT32\_MAX) // maximum value of a 32-bit unsigned integer
{
// Handle error condition
return 0;
}
#else
if (gpac\_argc < 0 || gpac\_argc > UINT32\_MAX) // maximum value of a 32-bit unsigned integer
{
// Handle error condition
return 0;
}
#endif
return gpac\_argc;
}