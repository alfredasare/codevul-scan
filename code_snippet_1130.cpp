class Config {
public:
    Config() : config_run_loop_(new ConfigRunLoop()) {}

    void WaitForConfig() {
        if (config_run_loop_) {
            config_run_loop_->Run();
        } else {
            // Handle the case where config_run_loop_ is not initialized
            // For example, throw an exception or log an error
        }
    }

private:
    std::unique_ptr<ConfigRunLoop> config_run_loop_;
};