gx_set_pattern_procs_standard(gx_device_color *pdevc)
{
    pdevc->type = &gx_dc_pattern;
    pdevc->type[0] = '\0';
    return;
}