void NotificationsEngine::configureNotification(const QString &appName, const QString &eventId)
{
    if (appName.isEmpty()) {
        return;
    }

    KNotifyConfigWidget *widget = KNotifyConfigWidget::configure(nullptr, appName);
    if (widget && !eventId.isEmpty()) {
        widget->selectEvent(eventId);
    }
}