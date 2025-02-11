void SetLeftUnavailable() {
    if (mbptr_ == nullptr) {
        // Handle the null case appropriately, e.g., logging an error or throwing an exception.
        return;
    }

    mbptr_->left_available = 0;

    if (num_planes_ > 0 && block_size_ > 0 && stride_ >= 0) {
        for (int p = 0; p < num_planes_; p++) {
            for (int i = -1; i < block_size_; ++i) {
                if (i * stride_ >= 0 && i * stride_ < static_cast<int>(sizeof(data_ptr_[0]))) {
                    data_ptr_[p][i * stride_ - 1] = 129;
                }
            }
        }
    }
}