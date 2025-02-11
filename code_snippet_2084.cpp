Time XRRConfigTimes(XRRScreenConfiguration *config, Time *config_timestamp) {
    if (config_timestamp < &config->config_timestamp || config_timestamp > &config->config_timestamp + sizeof(Time)) {
        return -1; 
    }
    *config_timestamp = config->config_timestamp;
    return config->timestamp;
}