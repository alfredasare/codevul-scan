jsonb_delete_path(PG_FUNCTION_ARGS)
{
    //...
    if (ARR_NDIM(path) > 1 || ARR_ELEMSIZE(path) > INT_MAX)
        ereport(ERROR,
                (errcode(ERRCODE_ARRAY_SUBSCRIPT_ERROR),
                 errmsg("invalid path length")));

    deconstruct_array(path, TEXTOID, -1, false, 'i',
                      &path_elems, &path_nulls, &path_len,
                      sizeof(Datum) * path_len);

    if (path_len > 0)
    {
        // process path elements safely
    }

    //...
}