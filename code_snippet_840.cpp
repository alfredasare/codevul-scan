ExprDef *
ExprCreateUnary(enum expr_op_type op, enum expr_value_type type,
                ExprDef *child)
{
    EXPR_CREATE(ExprUnary, expr, op, type);
    if (child != NULL) {
        expr->unary.child = child;
        expr_node_incref(child); /* Increment reference count of child */
    }
    return expr;
}

void
expr_node_decref(ExprDef *node)
{
    if (node == NULL) {
        return;
    }
    node->refcount--;
    if (node->refcount == 0) {
        /* Free the node and any associated resources */
        free(node);
    }
}