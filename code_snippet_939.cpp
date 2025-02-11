checkStringLen(size_t len)
{
    if (len > (size_t)-1 / sizeof(jsonb_value))
    {
        ereport(ERROR,
                (errcode(ERRCODE_PROGRAM_LIMIT_EXCEEDED),
                 errmsg("string too long to represent as jsonb string"),
                 errdetail("Due to an implementation restriction, jsonb strings cannot exceed %zu bytes.",
                           (size_t)-1 / sizeof(jsonb_value))));
    }

    return len;
}