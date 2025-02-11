void PDFiumEngine::Form\_EmailTo(FPDF\_FORMFILLINFO\* param,
FPDF\_FILEHANDLER\* file\_handler,
FPDF\_WIDESTRING to,
FPDF\_WIDESTRING subject,
FPDF\_WIDESTRING cc,
FPDF\_WIDESTRING bcc,
FPDF\_WIDESTRING message) {
std::string to\_str = StringConvert::WideToMulti(to);
std::string subject\_str = StringConvert::WideToMulti(subject);
std::string cc\_str = StringConvert::WideToMulti(cc);
std::string bcc\_str = StringConvert::WideToMulti(bcc);
std::string message\_str = StringConvert::WideToMulti(message);

PDFiumEngine\* engine = static\_cast<PDFiumEngine\*>(param);
engine->client\_->Email(to\_str, cc\_str, bcc\_str, subject\_str, message\_str);
}