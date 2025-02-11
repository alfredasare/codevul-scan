static RAnalValue *anal_fill_im(RAnal *anal, st32 v) {
    RAnalValue *ret = r_anal_value_new();
    if (sizeof(ret->imm) > sizeof(st32)) {
        ret->imm = 0; // or handle overflow error as needed
    } else {
        ret->imm = v;
    }
    return ret;
}