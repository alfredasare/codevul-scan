ExprResolveLhs(struct xkb_context *ctx, const ExprDef *expr,
           const char **elem_rtrn, const char **field_rtrn,
           ExprDef **index_rtrn)
{
    switch (expr->expr.op) {
    case EXPR_IDENT:
        *elem_rtrn = NULL;
        *field_rtrn = xkb_atom_text(ctx, expr->ident.ident);
        if (*field_rtrn == NULL) {
            return false;
        }
        *index_rtrn = NULL;
        return true;
    case EXPR_FIELD_REF:
        *elem_rtrn = xkb_atom_text(ctx, expr->field_ref.element);
        if (*elem_rtrn == NULL) {
            return false;
        }
        *field_rtrn = xkb_atom_text(ctx, expr->field_ref.field);
        if (*field_rtrn == NULL) {
            return false;
        }
        *index_rtrn = NULL;
        return true;
    case EXPR_ARRAY_REF:
        *elem_rtrn = xkb_atom_text(ctx, expr->array_ref.element);
        if (*elem_rtrn == NULL) {
            return false;
        }
        *field_rtrn = xkb_atom_text(ctx, expr->array_ref.field);
        if (*field_rtrn == NULL) {
            return false;
        }
        *index_rtrn = expr->array_ref.entry;
        return true;
    default:
        break;
    }
    log_wsgo(ctx, "Unexpected operator %d in ResolveLhs\n", expr->expr.op);
    return false;
}