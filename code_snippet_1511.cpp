c++
void ClipboardMessageFilter::OnReadCustomData(ui::ClipboardType clipboard_type,
                                             const base::string16& type,
                                             base::string16* result) {
  if (clipboard_type < ui::ClipboardType::FIRST || clipboard_type > ui::ClipboardType::LAST) {
    // Invalid clipboard type, handle the situation
    return;
  }

  if (type.empty()) {
    // Invalid type, handle the situation
    return;
  }

  GetClipboard()->ReadCustomData(clipboard_type, type, result);
}