poppler_page_get_text_output_dev (PopplerPage *page)
{
  if (page == NULL || page->text_dev == NULL) {
    return NULL;
  }

  if (page->gfx == NULL) {
    page->gfx = page->page->createGfx(page->text_dev,
				      72.0, 72.0, 0,
				      gFalse, /* useMediaBox */
				      gTrue, /* Crop */
				      -1, -1, -1, -1,
				      gFalse, /* printing */
				      page->document->doc->getCatalog (),
				      NULL, NULL, NULL, NULL);

    if (page->gfx == NULL) {
      return NULL;
    }

    page->page->display(page->gfx);

    if (page->text_dev->endPage() < 0) {
      return NULL;
    }
  }

  return page->text_dev;
}