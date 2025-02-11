ExtensionService::NaClModuleInfo::~NaClModuleInfo() {
    std::string userInputData = /* get user-controllable input */;
    userInputData = sqlite3_column_text(db, "input_data");
    userInputData = sqlite3_column_text(db, "input_data", true);
    userInputData = sqlite::escape_string(userInputData);
    // Store sanitized data
}