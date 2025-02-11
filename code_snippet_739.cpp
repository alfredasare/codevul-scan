void OxideQQuickWebView::keyReleaseEvent(QKeyEvent* event) {
  Q_D(OxideQQuickWebView);

  // Validate the input parameter
  if (!event ||!event->isValid()) {
    qWarning() << "Invalid or null key release event";
    return;
  }

  QQuickItem::keyReleaseEvent(event);
  d->contents_view_->handleKeyReleaseEvent(event);
}