void CheckConfigsCountForClient(const scoped_refptr<PlatformSensor>& sensor,
                                PlatformSensor::Client* client,
                                size_t expected_count) {
  auto client_entry = sensor->GetConfigMapForTesting().find(client);
  if (sensor->GetConfigMapForTesting().end() == client_entry && 0u != expected_count) {
    LOG(ERROR) << "Client not found in sensor config map, but an expected count was provided";
    return;
  }
  if (sensor->GetConfigMapForTesting().end() != client_entry) {
    EXPECT_EQ(expected_count, client_entry->second.size());
  }
}