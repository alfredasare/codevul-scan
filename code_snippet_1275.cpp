void PDFiumEngine::Form_EmailTo(FPDF_FORMFILLINFO* param,
                                FPDF_FILEHANDLER* file_handler,
                                const FPDF_WIDESTRING& to,
                                const FPDF_WIDESTRING& subject,
                                const FPDF_WIDESTRING& cc,
                                const FPDF_WIDESTRING& bcc,
                                const FPDF_WIDESTRING& message) {
  std::string to_str = WideStringToString(to);
  std::string subject_str = WideStringToString(subject);
  std::string cc_str = WideStringToString(cc);
  std::string bcc_str = WideStringToString(bcc);
  std::string message_str = WideStringToString(message);

  if (!to_str.empty() &&!subject_str.empty() &&!cc_str.empty() &&!bcc_str.empty() &&!message_str.empty()) {
    PDFiumEngine* engine = static_cast<PDFiumEngine*>(param);
    engine->client_->Email(to_str, cc_str, bcc_str, subject_str, message_str);
  }
}