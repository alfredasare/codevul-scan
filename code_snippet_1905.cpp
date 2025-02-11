int js_toint32(js_State *J, int idx)
{
    int num;
    js_value_t *val = jsV_tonumber(J, stackidx(J, idx));
    if (val->type == JS_VALUE_NUMBER && val->u.number >= INT32_MIN && val->u.number <= INT32_MAX) {
        num = (int)val->u.number;
    } else {
        num = 0;
    }
    return num;
}