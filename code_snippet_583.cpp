void RootDeviceControlMutexRelease ()
{
    if (RootDeviceControlMutex!= NULL) {
        KeReleaseMutex (&RootDeviceControlMutex, FALSE);
    }
}