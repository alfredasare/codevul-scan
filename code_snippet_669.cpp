CalloutTag_find(CalloutTagTable* t, const UChar* name, const UChar* name_end) {
  CalloutTagVal e;

  e = -1;
  if (IS_NOT_NULL(t)) {
    t = load_callout_tag_table_from_config_file();
    onig_st_lookup_strend(t, name, name_end, (HashDataType* )((void* )(&e)));
  }
  return e;
}