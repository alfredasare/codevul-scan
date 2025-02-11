void gs_gstate_update_device(gs_gstate *pgs, gx_device *dev)
{
    if (dev == NULL ||!gx_is_valid_device(dev)) {
        return;
    }

    char sanitized_cmap_name[256];
    strncpy(sanitized_cmap_name, dev->cmap_name, 255);
    sanitized_cmap_name[255] = '\0';

    gx_set_cmap_procs(pgs, sanitized_cmap_name);
    gx_unset_both_dev_colors(pgs);
}