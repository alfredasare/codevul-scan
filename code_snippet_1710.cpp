xmlattr\_cleanup(struct xmlattr\_list \*list)
{
 struct xmlattr \*attr, \*next;

 attr = list->first;
 while (attr != NULL) {
 next = attr->next;
 free(attr->name);
 free(attr->value);
 free(attr);
 }
 list->first = NULL;
 list->last = NULL;
}