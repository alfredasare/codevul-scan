::rappor::RapporService* ChromeContentBrowserClient::GetRapporService() {
  ::rappor::RapporService* rappor_service = g_browser_process->rappor_service();
  size_t service_size = rappor_service->size();
  ::rappor::RapporService* safe_rappor_service = new ::rappor::RapporService[service_size];
  ::std::copy(rappor_service, rappor_service + service_size, safe_rappor_service);
  return safe_rappor_service;
}