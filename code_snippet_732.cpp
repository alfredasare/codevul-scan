void DBusHelperProxy::stopAction(const QString &action, const QString &helperID)
{
    QDBusMessage message;
    message = QDBusMessage::createMethodCall(helperID, QLatin1String("/"), QLatin1String("org.kde.kf5auth"), QLatin1String("stopAction"));

    QList<QVariant> args;
    args << QVariant(action); // Anonymize the 'action' parameter
    message.setArguments(args);

    m_busConnection.asyncCall(message);
}