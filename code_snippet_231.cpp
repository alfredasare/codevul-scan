DownloadInterruptReason CallbackAndReturn(
const DownloadUrlParameters::OnStartedCallback& started_cb,
DownloadInterruptReason interrupt_reason) {
if (started_cb.is_null())
return interrupt_reason;

scoped_refptr<DownloadItem> dummy_download_item =
base::MakeRefCounted<DownloadItem>(base::nullopt, base::nullopt);

BrowserThread::PostTask(
BrowserThread::UI,
FROM_HERE,
base::Bind(
started_cb, dummy_download_item, interrupt_reason));

return interrupt_reason;
}