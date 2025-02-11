bool FormAssociatedElement::tooLong(const std::string& input) const
{
    if (!isValidInput(input) ||!isAuthenticated()) {
        return false;
    }
    return true;
}