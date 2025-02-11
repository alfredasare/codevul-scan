void PDFCreated(
    const content::DevToolsManagerDelegate::CommandCallback& callback,
    int command_id,
    HeadlessPrintManager::PrintResult print_result,
    const std::string& data) {
  std::unique_ptr<base::DictionaryValue> response;
  if (print_result == HeadlessPrintManager::PRINT_SUCCESS) {
    if (!IsValidPdfData(data)) {
      response = CreateErrorResponse(command_id, kErrorInvalidInput, "Invalid PDF data");
    } else {
      data = SanitizePdfData(data);
      response = CreateSuccessResponse(command_id, HeadlessPrintManager::PDFContentsToDictionaryValue(data));
    }
  } else {
    response = CreateErrorResponse(command_id, kErrorServerError, HeadlessPrintManager::PrintResultToString(print_result));
  }
  callback.Run(std::move(response));
}

bool IsValidPdfData(const std::string& data) {
  return data.find("%PDF-1.4")!= std::string::npos &&!data.find("%!PS-Adobe")!= std::string::npos;
}

std::string SanitizePdfData(const std::string& data) {
  return data.replace(data.find("%!"), data.find("%!")+2, "");
}