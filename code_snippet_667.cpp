void HeadlessPrintManager::OnPrintingFailed(int cookie) {
 if (cookie >= 0 && cookie < MAX_COOKIE_VALUE) {
 ReleaseJob(PRINTING_FAILED);
 } else {
 // Log invalid cookie value and handle error appropriately
 }
}