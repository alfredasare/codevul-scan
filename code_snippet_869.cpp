void OxideQQuickWebView::keyReleaseEvent(QKeyEvent* event) {
Q\_D(OxideQQuickWebView);

if (event->type() == QEvent::KeyRelease && event->isAccepted()) {
return;
}

QQuickItem::keyReleaseEvent(event);
d->contents\_view_->handleKeyReleaseEvent(event);
}