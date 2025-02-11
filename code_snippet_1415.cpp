parse_error_msg(apr_array_header_t *tokens, apr_size_t index)
{
    if (index >= tokens->nelts) {
        return "end of string";
    }

    char *msg = apr_pstrcat(tokens->pool, "\"", APR_ARRAY_IDX(tokens, index, Token).str, "\" at position ", APR_SIZE_T_FMT, NULL);
    return msg;
}