static inline bool setimpord(ELFOBJ* eobj, ut32 ord, RBinImport *ptr) {
    if (!eobj->imports_by_ord || ord >= eobj->imports_by_ord_size) {
        return false; // out-of-bounds access
    }
    if (eobj->imports_by_ord[ord]) {
        free(eobj->imports_by_ord[ord]->name);
        free(eobj->imports_by_ord[ord]);
    }
    if (ord < eobj->imports_by_ord_size) {
        eobj->imports_by_ord[ord] = malloc(sizeof(RBinImport));
        if (!eobj->imports_by_ord[ord]) {
            return false; // memory allocation failed
        }
        eobj->imports_by_ord[ord]->name = malloc(strlen(ptr->name) + 1);
        if (!eobj->imports_by_ord[ord]->name) {
            free(eobj->imports_by_ord[ord]);
            return false; // memory allocation failed
        }
        strcpy(eobj->imports_by_ord[ord]->name, ptr->name);
    }
    return true;
}