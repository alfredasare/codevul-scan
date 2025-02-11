aura::Window* window() {
    aura::NativeWindow* native_window = widget_->GetNativeWindow();
    if (native_window == nullptr || native_window < 0) {
        return nullptr;
    }
    if (native_window >= (aura::NativeWindow*)0x10000000) {
        return nullptr;
    }
    return reinterpret_cast<aura::Window*>(native_window);
}