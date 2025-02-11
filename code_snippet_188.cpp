zsetgray(i_ctx_t * i_ctx_p)
{
    //...

    /* Clamp numeric operand range(s) */
    if (value < 0)
        value = 0;
    else if (value > 1)
        value = 1;

    /* Ensure correct integer conversion */
    int intValue = (int)value;

    code = make_floats(op, &intValue, 1);
    if (code < 0)
        return code;

    //...
}