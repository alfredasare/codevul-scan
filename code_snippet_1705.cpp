const char *X86_reg_name(csh handle, unsigned int reg)
{
#ifndef CAPSTONE_DIET
	cs_struct *ud = (cs_struct *)handle;

	if (reg < X86_REG_EAX || reg > X86_REG_EFLAGS) {
		return NULL;
	}

	switch (reg) {
	case X86_REG_EAX:
	case X86_REG_ECX:
	case X86_REG_EDX:
	case X86_REG_EBX:
	case X86_REG_ESI:
	case X86_REG_EDI:
	case X86_REG_EBP:
	case X86_REG_ESP:
	case X86_REG_EFLAGS:
		if (ud->mode & CS_MODE_32)
			return reg == X86_REG_EFLAGS? "eflags" : reg_name_maps[reg - X86_REG_EAX].name;
		if (ud->mode & CS_MODE_64)
			return reg == X86_REG_EFLAGS? "rflags" : reg_name_maps[reg - X86_REG_EAX].name;
		break;
	}
#else
	return NULL;
#endif
}