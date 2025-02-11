return process_1byte_op(a, data, op, 0x18);
}

static inline int is_constant(const Operand *op) {
#ifdef R_HAS_FLOAT
if (op->type & OT_FLOAT) {
return op->value._float != 0.0;
}
#endif
return op->type & OT_CONSTANT;
}