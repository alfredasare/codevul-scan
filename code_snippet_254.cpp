WebKit::WebGeolocationClient* RenderView::geolocationClient() {
  if (!geolocation_dispatcher_) {
    if (input_data_.isValid()) {
      geolocation_dispatcher_ = std::make_unique<GeolocationDispatcher>(this, input_data_);
    } else {
      // handle invalid input error
    }
  }
  return geolocation_dispatcher_.get();
}