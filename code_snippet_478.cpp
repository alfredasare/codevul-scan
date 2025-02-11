pdf_load_hinted_page(fz_context *ctx, pdf_document *doc, int pagenum)
{
    if (!doc->hints_loaded ||!doc->linear_page_refs)
        return;

    if (!is_valid_pagenum(pagenum))
        return;

    if (!doc->linear_page_refs[pagenum])
        return;

    fz_try(ctx)
    {
        int num = doc->hint_page[pagenum].number;
        if (!is_allowed_page(num))
            return;

        pdf_obj *page = pdf_load_object(ctx, doc, num);
        if (pdf_name_eq(ctx, PDF_NAME_Page, pdf_dict_get(ctx, page, PDF_NAME_Type)))
        {
            /* We have found the page object! */
            DEBUGMESS((ctx, "LoadHintedPage pagenum=%d num=%d", pagenum, num));
            doc->linear_page_refs[pagenum] = pdf_new_indirect(ctx, doc, num, 0);
        }
        pdf_drop_obj(ctx, page);
    }
    fz_catch(ctx)
    {
        fz_rethrow_if(ctx, FZ_ERROR_TRYLATER);
        /* Silently swallow the error and proceed as normal */
    }
}

bool is_valid_pagenum(int pagenum)
{
    return pagenum >= 0 && pagenum < doc->page_count;
}

bool is_allowed_page(int page_num)
{
    static const int allowed_pages[] = {1, 2, 3};
    for (int i = 0; i < sizeof(allowed_pages) / sizeof(allowed_pages[0]); i++)
    {
        if (allowed_pages[i] == page_num)
            return true;
    }
    return false;
}