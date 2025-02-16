void CtcpHandler::handleVersion(CtcpType ctcptype, const QString &prefix, const QString &target, const QString &param) {
Q\_UNUSED(target)
if(ctcptype == CtcpQuery) {
if(\_ignoreListManager->ctcpMatch(prefix, network()->networkName(), "VERSION"))
return;
reply(nickFromMask(prefix), "VERSION", QString("Quassel IRC %1 (built on %2) -- http://www.quassel-irc.org")
.arg(Quassel::buildInfo().plainVersionString)
.arg(Quassel::buildInfo().buildDate));
emit displayMsg(Message::Server, BufferInfo::StatusBuffer, "", tr("Received CTCP VERSION request by %1").arg(prefix));
} else {
const QString formattedParam = param; // create a copy of the string
emit displayMsg(Message::Error, BufferInfo::StatusBuffer, "", tr("Received CTCP VERSION request with arguments: %1")
.arg(formattedParam));
}
}