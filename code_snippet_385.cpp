BpMemory::BpMemory(const sp<IBinder>& impl)
  : BpInterface<IMemory>(impl), mOffset(-1), mSize(-1)
{
}