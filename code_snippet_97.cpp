#include <map>

class PlatformSensor {
public:
    std::map<PlatformSensor::Client*, std::vector<int>> GetConfigMapForTesting() const {
        //... (existing implementation)
        return std::map<PlatformSensor::Client*, std::vector<int>>(config_map); // Return a copy of the configuration map
    }

    void CheckConfigsCountForClient(const scoped_refptr<PlatformSensor>& sensor, PlatformSensor::Client* client, size_t expected_count) {
        auto config_map_for_testing = sensor.GetConfigMapForTesting();
        auto client_entry = config_map_for_testing.find(client);
        if (config_map_for_testing.end() == client_entry) {
            EXPECT_EQ(0u, expected_count);
            return;
        }
        EXPECT_EQ(expected_count, client_entry->second.size());
    }

private:
    std::map<PlatformSensor::Client*, std::vector<int>> config_map;
};