void RenderMessageFilter::OnLoadFont(const FontDescriptor& font,
                                     IPC::Message* reply_msg) {
  auto result = std::make_unique<FontLoader::Result>();

  BrowserThread::PostTaskAndReply(
      BrowserThread::FILE, FROM_HERE,
      base::Bind(&FontLoader::LoadFont, font, result.get()),
      base::Bind(&RenderMessageFilter::SendLoadFontReply, this, reply_msg,
                 base::Passed(std::move(result))));
}