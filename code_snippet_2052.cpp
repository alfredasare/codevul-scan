void ChromeOSSendHandwritingStroke(InputMethodStatusConnection* connection,
                                 const HandwritingStroke& stroke) {
  if (!connection) {
    g_warning("Connection is null");
    return;
  }

  if (!stroke.IsValid()) {
    g_warning("Invalid handwriting stroke");
    return;
  }

  connection->SendHandwritingStroke(stroke);
}