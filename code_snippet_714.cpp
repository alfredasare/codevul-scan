bool dirent_is_file(const std::string &dir, const struct dirent *ent)
{
    if (ent->d_type == DT_REG)
        return true;

#ifndef WIN32
    struct stat st;
    std::string fname = dir + "/" + ent->d_name;

    if (ent->d_type == DT_UNKNOWN) {
        if (!lstat(fname.c_str(), &st)) {
            return S_ISREG(st.st_mode);
        } else {
            // Handle error or return false as appropriate
            //