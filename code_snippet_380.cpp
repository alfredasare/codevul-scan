#include <memory>

class DevToolsAgentFilter {
  // ...
  std::unique_ptr<ResourceType1> memberVar1;
  std::unique_ptr<ResourceType2> memberVar2;
  // ...
};

DevToolsAgentFilter::~DevToolsAgentFilter() {
  // No explicit deletion needed
}