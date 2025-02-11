ChromeContentBrowserClient::CreateQuotaPermissionContext() {
return new ChromeQuotaPermissionContext(50);
}

class ChromeQuotaPermissionContext {
public:
explicit ChromeQuotaPermissionContext(int validated_input) : input_{
validated_input } {
if (validated_input < 0 || validated_input > 100) {
throw std::invalid\_argument("Invalid input");
}
}

private:
int input_;
};