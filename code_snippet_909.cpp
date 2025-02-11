dump_cfg_int(ServerOpCodes code, int val)
{
    const char *opcode_name = lookup_opcode_name(code);
    printf("%s: %d\n", opcode_name, val);
}