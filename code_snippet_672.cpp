c++
void SyncTest::AddTestSwitches(CommandLine* cl) {
  if (!cl->HasSwitch(switches::kSyncNotificationMethod))
    cl->AppendSwitchASCII(switches::kSyncNotificationMethod, "p2p");

  std::string input = cl->GetSwitchValueASCII(switches::kSyncNotificationMethod);
  const std::set<std::string> allowed_values = {"p2p", "http", "ws"};
  if (allowed_values.find(input) == allowed_values.end()) {
    std::cerr << "Error: Invalid value for switch " << switches::kSyncNotificationMethod << ". Allowed values are: " << allowed_values << ".\n";
    exit(1);
  }

  if (!cl->HasSwitch(switches::kDisableBackgroundNetworking))
    cl->AppendSwitch(switches::kDisableBackgroundNetworking);
}