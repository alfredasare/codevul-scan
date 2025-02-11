static int opfdiv(RAsm *a, ut8 *data, const Opcode *op) {
	int l = 0;
	size_t data_size = get_data_size(data);
	switch (op->operands_count) {
		case 1:
			if ( op->operands[0].type & OT_MEMORY ) {
				if ( op->operands[0].type & OT_DWORD ) {
					data[l++] = 0xd8;
					data[l++] = 0x30 | op->operands[0].regs[0];
				} else if ( op->operands[0].type & OT_QWORD ) {
					data[l++] = 0xdc;
					data[l++] = 0x30 | op->operands[0].regs[0];
				} else {
					return -1;
				}
				if (l >= data_size) {
					return -1;