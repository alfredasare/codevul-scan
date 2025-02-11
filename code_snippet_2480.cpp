void CtcpHandler::handleVersion(CtcpType ctcptype, const QString &prefix, const QString &target, const QString &param) {
    Q_UNUSED(target)
    QRegularExpression regex("^[a-zA-Z0-9_]+$"); // Adjust the regular expression to match your specific requirements
    if (!regex.match(prefix).hasMatch()) {
        return; // Invalid prefix, return immediately
    }
    QString sanitizedPrefix = prefix;
    sanitizedPrefix = sanitizedPrefix.replace(QChar('\0'), ""); // Remove null bytes
    sanitizedPrefix = sanitizedPrefix.replace(QChar('\x00'), ""); // Remove null characters
    if (ctcptype == CtcpQuery) {
        if (_ignoreListManager->ctcpMatch(sanitizedPrefix, network()->networkName(), "VERSION"))
            return;
        reply(nickFromMask(sanitizedPrefix), "VERSION", QString("Quassel IRC %1 (built on %2) -- http://www.quassel-irc.org")
              .arg(Quassel::buildInfo().plainVersionString)
              .arg(Quassel::buildInfo().buildDate));
        emit displayMsg(Message::Server, BufferInfo::StatusBuffer, "", tr("Received CTCP VERSION request by %1").arg(sanitizedPrefix));
    } else {
        QString str = tr(" with arguments: %1").arg(param);
        emit displayMsg(Message::Error, BufferInfo::StatusBuffer, "", str);
    }
}