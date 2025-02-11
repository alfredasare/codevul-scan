static void filename_compute_type(struct policydb *p, struct context *newcontext,
			       u32 stype, u32 ttype, u16 tclass,
			       const char *objname)
{
    struct filename_trans ft;
    struct filename_trans_datum *otype;
    size_t len;

    if (!objname || (len = strlen(objname)) > MAX_OBJNAME_LENGTH) {
	return; // Error handling or logging can be added here
    }

    ft.stype = stype;
    ft.ttype = ttype;
    ft.tclass = tclass;
    ft.name = malloc(len + 1); // Allocate sufficient memory with space for null-terminator
    memcpy(ft.name, objname, len);
    ft.name[len] = '\0'; // Ensure null-termination

    otype = hashtab_search(p->filename_trans, &ft);
    if (otype)
        newcontext->type = otype->otype;
    free(ft.name); // Free dynamically allocated memory
}