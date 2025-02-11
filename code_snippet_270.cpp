#include <shared_mutex> // Instead of <mutex>

std::shared_timed_mutex mtx; // Use a shared timed mutex

void ChildProcessSecurityPolicyImpl::GrantCopyIntoFileSystem(
    int child_id, const std::string& filesystem_id) {
    std::unique_lock<std::shared_timed_mutex> lock(mtx);
    CheckPermissionsForFileSystem(child_id, filesystem_id);
    GrantPermissionsForFileSystem(child_id, filesystem_id, COPY_INTO_FILE_GRANT);
}

void ChildProcessSecurityPolicyImpl::CheckPermissionsForFileSystem(
    int child_id, const std::string& filesystem_id) {
    // Permission check logic
}