static ut32 adr(ArmOp *op, int addr) {
    ut32 data = UT32_MAX;
    ut64 at = 0LL;

    if (op->operands[1].type & ARM_CONSTANT) {
        at = op->operands[1].immediate - addr;
        at /= 4;
        if (at > (ut64)(UT32_MAX / 4)) {
            at = (ut64)(UT32_MAX / 4);
        }
    }

    data = 0x00000030;
    data += 0x01000000 * op->operands[0].reg;
    data += (at & 0xff) << 29;
    data += ((at >> 8) & 0xff) << 16;
    data += ((at >> 16) & 0xff) << 24;
    return data;
}