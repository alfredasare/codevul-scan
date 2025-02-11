void UpdateScreenInfo(float pixel_ratio) {
    if (client_hints_) {
        client_hints_->UpdateScreenInfo(pixel_ratio);
    } else {
        printf("Error: client_hints_ has already been freed\n");
        return;
    }
};