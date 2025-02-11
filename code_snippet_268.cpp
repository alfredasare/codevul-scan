c++
void ChildProcessSecurityPolicyImpl::GrantCopyIntoFileSystem(int child_id, const std::string& filesystem_id) {
  if (child_id < 0 || child_id >= MAX_CHILD_PROCESS_ID || 
      filesystem_id.empty() || filesystem_id.size() > MAX_FILESYSTEM_ID_LENGTH) {
    throw std::invalid_argument("Invalid child ID or file system ID");
  }

  GrantPermissionsForFileSystem(child_id, filesystem_id, COPY_INTO_FILE_GRANT);
}