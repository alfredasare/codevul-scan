gs_gstate_update_device(gs_gstate *pgs, gx_device *dev)
{
    if (dev && dev->color_info.num_components <= GX_MAX_COLORS) {
        gx_set_cmap_procs(pgs, dev);
    } else {
        // Handle the error case when the array index is out of bounds
        // ...
    }

    gx_unset_both_dev_colors(pgs);
}