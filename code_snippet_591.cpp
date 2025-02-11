void DBusHelperProxy::stopAction(const QString &action, const QString &helperID)
{
    if (!isValidAction(action) ||!isValidHelperID(helperID)) {
        qWarning() << "Invalid input";
        return;
    }

    QDBusMessage message;
    message = QDBusMessage::createMethodCall(helperID, QLatin1String("/"), QLatin1String("org.kde.kf5auth"), QLatin1String("stopAction"));

    QList<QVariant> args;
    args << action;
    message.setArguments(args);

    m_busConnection.asyncCall(message);
}

bool DBusHelperProxy::isValidAction(const QString &action)
{
    return action.length() <= 255 && action.isValid();
}

bool DBusHelperProxy::isValidHelperID(const QString &helperID)
{
    return helperID.length() <= 128 && helperID.isValid();
}