void OMXNodeInstance::onMessages(std::list<omx\_message> &messages) {
for (auto it = messages.begin(); it != messages.end(); ) {
if (it->message != nullptr && handleMessage(*it)) {
messages.erase(it++);
} else {
++it;
}
}

if (!messages.empty()) {
mObserver->onMessages(messages);
}
}