poppler_page_get_text_output_dev (PopplerPage *page)
{
  if (!page ||!page->page) {
    return NULL;
  }

  if (!page->text_dev) {
    page->text_dev = std::make_unique<TextOutputDev>(NULL, gTrue, gFalse, gFalse);

    if (page->gfx) {
      delete page->gfx;
      page->gfx = nullptr;
    }
    page->gfx = page->page->createGfx(page->text_dev,
				      72.0, 72.0, 0,
				      gFalse, /* useMediaBox */
				      gTrue, /* Crop */
				      -1, -1, -1, -1,
				      gFalse, /* printing */
				      page->document->doc->getCatalog (),
				      NULL, NULL, NULL, NULL);

    page->page->display(page->gfx);

    page->text_dev->endPage();
  }

  return page->text_dev.get();
}