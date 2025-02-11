Fclose\_sec(iop)
{
#ifdef HAS\_SAVED\_IDS\_AND\_SETEUID
return fclose\_sec(iop);
#else
return pclose(iop);
#endif
}