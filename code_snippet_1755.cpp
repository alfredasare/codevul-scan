void ColorChooserDialog::CopyCustomColors(COLORREF* src, COLORREF* dst) {
    std::copy(src, src + arraysize(g_custom_colors), dst);
}