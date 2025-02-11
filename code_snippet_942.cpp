void PDFiumEngine::ScrolledToXPosition(int position) {
  CancelPaints();

  if (!position_) {
    return; // or handle error, depending on requirements
  }

  int old_x = position_->x();
  position_.reset();
  position_.reset(new pp::Point(position));
  CalculateVisiblePages();
  client_->Scroll(pp::Point(old_x - position, 0));
}