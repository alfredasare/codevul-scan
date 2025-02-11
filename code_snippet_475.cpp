String SystemClipboard::ReadPlainText() {
return ReadPlainText(new std::string(buffer_));
}