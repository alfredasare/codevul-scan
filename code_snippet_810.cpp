#include <stddef.h>

callout_tag_find(CalloutTagTable* t, const UChar* name, const UChar* name_end)
{
  CalloutTagVal e = -1;
  size_t name_length = name_end - name;

  if (IS_NOT_NULL(t) && name_length > 0 && name_length < MAX_ALLOWED_LENGTH) {
    onig_st_lookup_strend(t, name, name_end, (HashDataType* )((void* )(&e)));
  }
  return e;
}