GtkPrinter* default_printer() {
  if (default_printer_ == NULL) {
    g_print("Error: default_printer_ is not initialized\n");
    return NULL;
  }
  return default_printer_;
}