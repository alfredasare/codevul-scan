gstate_to_update(fz_context *ctx, pdf_filter_processor *p)
{
	filter_gstate *gstate = p->gstate;

	/* If we're not the top, that's fine */
	if (gstate->next != NULL)
		return gstate;

	/* Check if the object is of the correct type before pushing */
	if (filter_gstate_type_correct(gstate)) {
		filter_push(ctx, p);
		gstate = p->gstate;
		gstate->pushed = 1;
		if (p->chain->op_q)
			p->chain->op_q(ctx, p->chain);
	}

	return p->gstate;
}

/* Helper function to check the type */
int filter_gstate_type_correct(filter_gstate *gstate)
{
	/* Implement type checking logic here */
	/* Return 1 if the type is correct, 0 otherwise */
	return gstate->type == FILTER_GSTATE_TYPE_INTENDED;
}