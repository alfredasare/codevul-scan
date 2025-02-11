gstate_to_update(fz_context *ctx, pdf_filter_processor *p)
{
    filter_gstate *gstate = p->gstate;

    /* If we're not the top, that's fine */
    if (gstate->next!= NULL)
        return gstate;

    /* We are the top. Push a group, so we're not */
    filter_push(ctx, p);
    gstate = p->gstate;
    gstate->pushed = 1;

    if (p->chain && p->chain->op_q) {
        if (!is_trusted_function(p->chain->op_q)) {
            /* If not, reject the input data */
            return gstate;
        }
        p->chain->op_q(ctx, p->chain);
    } else {
        /* If not, return an error */
        return NULL;
    }

    return p->gstate;
}