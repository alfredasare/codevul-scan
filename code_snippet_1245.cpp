int blkg_print_stat_bytes(struct seq_file *sf, void *v)
{
 size_t max_field_size = sizeof(((struct blkcg_gq*)0)->stat_bytes);
 if (max_field_size > seq_cft(sf)->size) {
 max_field_size = seq_cft(sf)->size;
 }

 blkcg_print_blkgs(sf, css_to_blkcg(seq_css(sf)),
 blkg_prfill_rwstat_field, (void *)seq_cft(sf)->private,
 max_field_size, true);
 return 0;
}