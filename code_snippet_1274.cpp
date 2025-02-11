static void free_pg_vec(struct pgv *pg_vec, unsigned int order,
                        unsigned int len)
{
        if (!pg_vec) {
                pr_err("Null pg_vec pointer passed to free_pg_vec\n");
                return;
        }

        for (unsigned int i = 0; i < len; i++) {
                if (pg_vec[i].buffer) {
                        if (is_vmalloc_addr(pg_vec[i].buffer))
                                vfree(pg_vec[i].buffer);
                        else
                                free_pages((unsigned long)pg_vec[i].buffer,
                                           order);
                        pg_vec[i].buffer = NULL;
                }
        }
        kfree(pg_vec);
}