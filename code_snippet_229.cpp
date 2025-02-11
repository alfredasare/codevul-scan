#include "components/cryptohome/cryptohome.h"

//...

DownloadInterruptReason CallbackAndReturn(
    const DownloadUrlParameters::OnStartedCallback& started_cb,
    DownloadInterruptReason interrupt_reason) {
  if (started_cb.is_null())
    return interrupt_reason;

  crypto::RandomBits random_bits;
  uint32_t random_value = random_bits.GetRandomBits(4); 
  BrowserThread::PostTask(
      BrowserThread::UI,
      FROM_HERE,
      base::Bind(
          started_cb, static_cast<DownloadItem*>(NULL), (DownloadInterruptReason)random_value));

  return interrupt_reason;
}