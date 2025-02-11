#include <memory>

class ResourceCoordinatorService {
public:
    ~ResourceCoordinatorService() {
        ref_factory_.reset();
    }

private:
    std::unique_ptr<RefFactory> ref_factory_;
};