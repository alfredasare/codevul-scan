parse\_error\_msg(apr\_array\_header\_t \*tokens, apr\_size\_t index)
{
if (index >= tokens->nelts) {
return "end of string";
}

const Token *token = &APR\_ARRAY\_IDX(tokens, index, Token);
return apr\_psprintf(tokens->pool, "\"%s\" at position %lu", token->str, token->offset);
}