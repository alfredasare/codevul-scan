std::set<std::string> validPaths = {"./", "./dir1/", "./dir2/"};
for (auto& file : files_) {
    std::string filePath = file.path();
    size_t pos = filePath.find_last_of('/');
    if (pos!= std::string::npos && validPaths.find(filePath.substr(0, pos + 1))!= validPaths.end()) {
        std::remove(filePath.c_str());
    }
}