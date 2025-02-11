void NotificationsEngine::configureNotification(const QString &appName, const QString &eventId)
{
    KNotifyConfigWidget *widget = KNotifyConfigWidget::configure(nullptr, appName);
    try {
        if (!eventId.isEmpty()) {
            widget->selectEvent(eventId);
        }
    } catch (const std::runtime_error &e) {
        // Log the error securely
        qWarning() << "An error occurred: " << e.what();
    }
}