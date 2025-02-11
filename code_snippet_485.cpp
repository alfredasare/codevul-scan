void sgpd_del(GF_Box *a)
{
	GF_SampleGroupDescriptionBox *p = (GF_SampleGroupDescriptionBox *)a;
	while (gf_list_count(p->group_descriptions)) {
		void *ptr = gf_list_last(p->group_descriptions);
		if (ptr != NULL && valid_ptr(p->grouping_type, ptr) == true) { // Add validation for grouping_type and ptr
			sgpd_del_entry(p->grouping_type, ptr);
			gf_list_rem_last(p->group_descriptions);
		}
	}
	gf_list_del(p->group_descriptions);
	gf_free(p);
}

// Add this new function to validate the pointer based on the grouping_type
bool valid_ptr(int grouping_type, void *ptr)
{
    // Perform validation based on the grouping_type and ptr
    // For example, if grouping_type is related to memory allocation size,
    // ensure that the ptr points to a memory block with a correct size.

    // Return true if the pointer is valid; false otherwise
}