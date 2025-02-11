CopyInterps(CompatInfo *info, bool needSymbol, enum xkb_match_operation pred,
            struct collect *collect)
{
    SymInterpInfo *si;
    XkbSymInterpret interp;

    darray_foreach(si, info->interps) {
        if (si->interp.match == pred &&
            (si->interp.sym != XKB_KEY_NoSymbol) == needSymbol) {
            interp = si->interp;
            interp.symbols = xkb_sym_interp_alloc_copy(interp.symbols);
            if (!interp.symbols) {
                // Handle memory allocation failure
                return;
            }
            darray_append(collect->sym_interprets, interp);
        }
    }
}