void RootDeviceControlMutexRelease()
{
if (KeGetCurrentThread() == KeGetOwnerThread(&RootDeviceControlMutex))
KeReleaseMutex(&RootDeviceControlMutex, FALSE);
}