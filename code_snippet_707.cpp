ExprCreateUnary(enum expr_op_type op, enum expr_value_type type, ExprDef *child)
{
    if (child == NULL || child->expr_def == NULL) {
        return NULL;
    }
    EXPR_CREATE(ExprUnary, expr, op, type);
    expr->unary.child = child;
    return expr;
}