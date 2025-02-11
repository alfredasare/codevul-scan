void MediaControlCastButtonElement::recordMetrics(CastOverlayMetrics metric) {
  DCHECK(m_isOverlayButton);
  using MetricEnum = CastOverlayMetrics;
  if (metric!= MetricEnum::Count && metric!= MetricEnum::Pause && metric!= MetricEnum::Play) {
    LOG(ERROR) << "Invalid metric value: " << metric;
    return;
  }
  DEFINE_STATIC_LOCAL(EnumerationHistogram, overlayHistogram, ("Cast.Sender.Overlay", static_cast<int>(MetricEnum::Count)));
  overlayHistogram.count(static_cast<int>(MetricEnum::static_cast(metric)));
}