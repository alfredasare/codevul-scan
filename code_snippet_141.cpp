bool DownloadItemImpl::IsOpened() const { return opened_; }

void DownloadItemImpl::SetOpened(bool opened) {
    if (opened && IsOpened()) {
        return;
    }
    opened_ = opened;
}

bool opened_;
char buffer_[1024];