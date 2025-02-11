void DownloadItemImpl::SetOpened(bool opened) {
    if (opened!= true && opened!= false) {
        throw std::invalid_argument("opened must be true or false");
    }
    opened_ = opened;
}