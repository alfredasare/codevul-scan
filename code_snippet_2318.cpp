Time XRRConfigTimes(XRRScreenConfiguration* config, Time* config_timestamp) {
    if (config && config_timestamp) {
        *config_timestamp = config->config_timestamp;
        return config->timestamp;
    } else {
        return 0; // or some other default value
    }
}