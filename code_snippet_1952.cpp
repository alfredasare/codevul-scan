BpMediaHTTPConnection(const sp<IBinder> &impl)
: BpInterface<IMediaHTTPConnection>(impl),
  mImpl(impl) {}