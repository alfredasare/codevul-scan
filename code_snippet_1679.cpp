const int kMaxTypeLength = 128; // Adjust this value as needed

void ClipboardMessageFilter::OnReadCustomData(ui::ClipboardType clipboard_type,
                                              const base::string16& type,
                                              base::string16* result) {
    if (type.length() > kMaxTypeLength) {
        LOG(WARNING) << "Clipped data type exceeds maximum allowed length";
        return;
    }

    GetClipboard()->ReadCustomData(clipboard_type, base::string16(type.substr(0, kMaxTypeLength)), result);
}