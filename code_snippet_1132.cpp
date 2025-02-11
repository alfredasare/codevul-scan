gs\_currentlabicc(const gs\_gstate \* pgs, gs\_param\_string \* pval)
{
    static const char \*const rfs = LAB\_ICC;

    if (pgs->icc\_manager->lab\_profile == NULL) {
        pval->data = (const byte \*)rfs;
    } else {
        pval->data = (const byte \*)(pgs->icc\_manager->lab\_profile->name);
    }
    pval->size = strlen((const char \*)pval->data);
    pval->persistent = true;
}