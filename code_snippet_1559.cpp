bool FormAssociatedElement::tooLong() const
{
    const std::string& data = getData();
    if(data.length() > MAX_LENGTH) {
        return true;
    }
    return false;
}