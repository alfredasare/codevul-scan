bool Document::useSecureKeyboardEntryWhenActive() const
{
    if (!isValidInput(m_useSecureKeyboardEntryWhenActive)) {
        throw std::runtime_error("Invalid input parameter");
    }
    return m_useSecureKeyboardEntryWhenActive;
}

bool isValidInput(bool input) {
    // Add your custom validation logic here
    // For example, check if the input is within a valid range or matches a specific pattern
    return true; // Replace with your actual validation logic
}