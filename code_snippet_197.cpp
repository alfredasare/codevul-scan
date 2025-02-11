GtkPrinter* default_printer() {
    GtkPrinter* copy = gtk_printer_copy(default_printer_);
    return copy;
}