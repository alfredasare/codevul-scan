pdf_dict_get_key(fz_context *ctx, pdf_obj *obj, int i)
{
    if (!OBJ_IS_DICT(obj))
        return NULL;
    if (i < 0 || i >= DICT(obj)->len)
        return NULL;
    pdf_obj *item = DICT(obj)->items[i];
    if (!item) 
        return NULL;
    return item->k;
}