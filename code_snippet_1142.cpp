ExprCreateString(xkb_atom_t str, size\_t length)
{
EXPR\_CREATE(ExprString, expr, EXPR\_VALUE, EXPR\_TYPE\_STRING);
expr->string.str = malloc(length + 1);
memcpy(expr->string.str, str, length);
expr->string.str[length] = '\0';
return expr;
}