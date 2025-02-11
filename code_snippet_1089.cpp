void PDFiumEngine::ScrolledToXPosition(int position) {
  CancelPaints();

  int old_x = position_.x();
  position_.set_x(position);
  CalculateVisiblePages();
  pp::Point scrollAmount(old_x - position, 0);
  client_->Scroll(scrollAmount);
  // Use scrollAmount instead of old_x for any further calculations
}