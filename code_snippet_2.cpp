const char* Track::GetNameAsUTF8() const {
    std::string name = m_info.nameAsUTF8;
    size_t pos = 0;
    while ((pos = name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-. "))!= std::string::npos) {
        name.erase(pos, 1);
    }
    return name.c_str();
}