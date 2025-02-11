#include <string>
#include <vector>

class MockNetworkTransaction {
public:
    void SetBeforeHeadersSentCallback(const BeforeHeadersSentCallback& callback) {
        // Define a list of allowed directory paths
        std::vector<std::string> allowedPaths = {"./", "../"};

        // Validate the input path
        if (!IsValidPath(callback.GetPath(), allowedPaths)) {
            throw std::runtime_error("Invalid path");
        }

        // Call the callback function with the validated path
        callback.callback();
    }

private:
    bool IsValidPath(const std::string& path, const std::vector<std::string>& allowedPaths) {
        // Check if the path is in the allowed list
        for (const auto& allowedPath : allowedPaths) {
            if (path.find(allowedPath)!= std::string::npos) {
                return true;
            }
        }
        return false;
    }
};