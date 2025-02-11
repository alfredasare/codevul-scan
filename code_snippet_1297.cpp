static int opsldt(RAsm *a, ut8 *data, const Opcode *op) {
int l = 0;
switch (op->operands\_count) {
case 1:
if (a->bits == 64) {
data[l++] = 0x48;
}
data[l++] = 0x0f;
data[l++] = 0x00;
if (op->operands[0].type & OT\_MEMORY) {
if (sizeof(op->operands[0].regs[0]) == 1) {
data[l++] = 0x00 | op->operands[0].regs[0];
}
} else {
if (sizeof(op->operands[0].reg) == 1) {
data[l++] = 0xc0 | op->operands[0].reg;
}
}
break;
default:
return -1;
}
return l;
}