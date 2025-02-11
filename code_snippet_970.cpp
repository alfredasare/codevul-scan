void UsbDeviceImpl::OnOpenRequestComplete(const OpenCallback& callback,
dbus::FileDescriptor fd) {
if (fd.is_valid()) {
blocking\_task\_runner-\>PostTask(
FROM\_HERE, base::Bind(&UsbDeviceImpl::OpenOnBlockingThreadWithFd, this,
base::Passed(&fd), callback));
} else {
// Handle invalid file descriptor case
}
}