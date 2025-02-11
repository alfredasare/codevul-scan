void RenderMessageFilter::OnLoadFont(const FontDescriptor& font,
                                     IPC::Message* reply_msg) {
  FontLoader::Result* result = new FontLoader::Result;
  try {
    BrowserThread::PostTaskAndReply(
        BrowserThread::FILE, FROM_HERE,
        base::Bind(&FontLoader::LoadFont, font, result),
        base::Bind(&RenderMessageFilter::SendLoadFontReply, this, reply_msg,
                   base::Owned(result)));
  } catch (...) {
    delete result; // Delete result to prevent memory leaks
    LOG(ERROR) << "Error loading font: " << base::StringPrintf("%s", strerror(errno));
  }
}