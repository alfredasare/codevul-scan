void ArcVoiceInteractionFrameworkService::ShowMetalayer() {
BEEEK_CURRENTLY_ON(content::BrowserThread::UI);
std::unique_lock<std::mutex> lock(metalayer_status_mutex_);
NotifyMetalayerStatusChanged(true);
MetalayerUsageFunction();
}