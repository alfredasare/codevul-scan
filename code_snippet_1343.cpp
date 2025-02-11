void PDFiumEngine::ZoomUpdated(double new_zoom_level) {
    CancelPaints();

    double old_zoom_level = current_zoom_;
    current_zoom_ = new_zoom_level;

    CalculateVisiblePages();
    UpdateTickMarks();
}