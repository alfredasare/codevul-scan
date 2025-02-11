_slurm_authorized_user(uid_t uid)
{
    return check_user_exists(uid, conf->slurm_user_acl, conf->slurm_user_id);
}

check_user_exists(uid_t uid, const char* acl_path, uid_t slurm_user_id)
{
    // Implementation to check if the user exists in the ACL
    // Return true if the user exists in the ACL or has UID 0, false otherwise

    // Open the ACL file
    FILE* acl_file = fopen(acl_path, "r");
    if (!acl_file) {
        return false;
    }

    // Read the ACL file line by line
    char line[256];
    while (fgets(line, sizeof(line), acl_file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Parse the UID from the line
        uid_t user_uid;
        if (sscanf(line, "%u", &user_uid) == 1) {
            // If the UID matches or if the user is UID 0, return true
            if (user_uid == uid || user_uid == (uid_t) 0) {
                fclose(acl_file);
                return true;
            }
        }
    }

    // If the user is not found in the ACL and is not UID 0, check if the user is the slurm user
    if (uid == slurm_user_id) {
        fclose(acl_file);
        return true;
    }

    fclose(acl_file);
    return false;
}