vips_foreign_load_generate( VipsRegion *or, 
void *seq, void *a, void *b, gboolean *stop )
{
    VipsRegion *ir = (VipsRegion *) seq;

    VipsRect *r = &or->valid;

    /* Ask for input we need.
     */
    int prepare_error = vips_region_prepare( ir, r );
    if( prepare_error!= 0 )
    {
        printf("Error preparing region: %d\n");
        return -1;
    }

    /* Attach output region to that.
     */
    int region_error = vips_region_region( or, ir, r, r->left, r->top );
    if( region_error!= 0 )
    {
        printf("Error attaching region: %d\n");
        return -1;
    }

    return 0;
}