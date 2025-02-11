#include <filesystem>

bool dirent_is_file(const std::string &dir, struct dirent *ent)
{
    if (ent->d_type == DT_REG)
        return true;

#ifndef WIN32
    if (ent->d_type == DT_UNKNOWN) {
        std::filesystem::path path(dir);
        path /= ent->d_name;
        if (std::filesystem::is_regular_file(path))
            return true;
    }
#endif
    return false;
}