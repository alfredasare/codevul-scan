pdf_obj *page = NULL;

pdf_load_hinted_page(fz_context *ctx, pdf_document *doc, int pagenum)
{
	if (!doc->hints_loaded || !doc->linear_page_refs)
		return;

	if (doc->linear_page_refs[pagenum])
		return;

	fz_try(ctx)
	{
		int num = doc->hint_page[pagenum].number;
		page = pdf_load_object(ctx, doc, num);
		if (page && pdf_name_eq(ctx, PDF_NAME_Page, pdf_dict_get(ctx, page, PDF_NAME_Type)))
		{
			/* We have found the page object! */
			DEBUGMESS((ctx, "LoadHintedPage pagenum=%d num=%d", pagenum, num));
			doc->linear_page_refs[pagenum] = pdf_new_indirect(ctx, doc, num, 0);
		}
	}
	fz_catch(ctx)
	{
		if (fz_caught(ctx) == FZ_ERROR_TRYLATER)
			return FZ_ERROR_TRYLATER;

		/* Silently swallow the error and proceed as normal */
	}
	pdf_drop_obj(ctx, page);
}