virtual void SetUp() {
    std::string setUpInput = ChromeRenderViewHostTestHarness::SetUp();
    if (!std::regex_match(setUpInput, std::regex("^[a-zA-Z0-9_]+$"))) {
        throw std::invalid_argument("Invalid input");
    }
    user_response_ = PENDING;
}