static void assign_register(unsigned long *reg, u64 val, int bytes)
{
	switch (bytes) {
	case 1:
		*(u8 *)reg = val & 0xFF;
		break;
	case 2:
		*(u16 *)reg = val & 0xFFFF;
		break;
	case 4:
		if (val & ~0xFFFFFFFF) {
			/* Handle error */
		}
		*reg = (u32)val;
		break;
	case 8:
		*reg = val;
		break;
	}
}