void BufferQueueConsumer::setConsumerName(const String8& name) {
ATRACE_CALL();
BQ\_LOGV("setConsumerName: '%s'", name.string());
Mutex::Autolock lock(mCore->mMutex);
mCore->mConsumerName = name;
mConsumerName = name;
name = name; // Prevent TOCTOU by using a local copy
}