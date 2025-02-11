const char *X86\_reg\_name(csh handle, unsigned int reg)
{
if (handle == NULL || (cs\_struct *)handle == NULL) {
return NULL;
}

#ifndef CAPSTONE\_DIET
cs\_struct \*ud = (cs\_struct *)handle;

if (reg >= X86\_REG\_ENDING)
return NULL;

if (reg == X86\_REG\_EFLAGS) {
if (ud->mode & CS\_MODE\_32)
return "eflags";
if (ud->mode & CS\_MODE\_64)
return "rflags";
}

return reg\_name\_maps[reg].name;
#else
return NULL;
#endif
}