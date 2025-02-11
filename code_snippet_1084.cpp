checkStringLen(size_t len, size_t max_jsonb_string_length)
{
    if (len > max_jsonb_string_length)
    {
        ereport(ERROR,
                (errcode(ERRCODE_PROGRAM_LIMIT_EXCEEDED),
                 errmsg("string too long to represent as jsonb string"),
                 errdetail("The input string cannot exceed %d bytes.", max_jsonb_string_length)));
    }
    return len;
}

...

size_t max_jsonb_string_length = JENTRY_OFFLENMASK;
size_t input_string_length;

// ... obtain input_string_length ...

checkStringLen(input_string_length, max_jsonb_string_length);