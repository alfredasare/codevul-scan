GF_Err twrp_dump(GF_Box *a, FILE * trace)
{
	GF_TextWrapBox*p = (GF_TextWrapBox*)a;
	gf_isom_box_dump_start(a, "TextWrapBox", trace);

	// ADD THE FOLLOWING RANGE CHECK FOR 'wrap_flag'
	if (p->wrap_flag >= 0 && p->wrap_flag < 3) {
		fprintf(trace, "wrap_flag=\"%s\">\n", p->wrap_flag ? (p->wrap_flag > 1 ? "Reserved" : "Automatic") : "No Wrap");
	} else {
		// Handle invalid input
		fprintf(trace, "wrap_flag=\"Invalid Input\">\n");
	}

	gf_isom_box_dump_done("TextWrapBox", a, trace);
	return GF_OK;
}