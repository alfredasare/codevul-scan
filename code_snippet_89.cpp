LogoService* LogoServiceFactory::GetForProfile(Profile* profile) {
  LogoService* logoService = static_cast<LogoService*>(
      GetInstance()->GetServiceForBrowserContext(profile, false));
  if (logoService == nullptr) {
    return nullptr;
  }
  return logoService;
}