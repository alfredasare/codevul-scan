#include <r_util/r_util.h>

static RAnalValue *anal_fill_im(RAnal *anal, st32 v) {
    RAnalValue *ret = r_anal_value_new();
    if (!r_num_u64_check(v, &ret->imm)) {
        return ret;
    } else {
        r_anal_value_free(ret);
        return NULL;
    }
}