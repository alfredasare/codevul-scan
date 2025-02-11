bool BaseMultipleFieldsDateAndTimeInputType::shouldHaveSecondField(const DateComponents& date) const
{
    return isSecondFieldRequired(date);
}

bool BaseMultipleFieldsDateAndTimeInputType::isSecondFieldRequired(const DateComponents& date) const
{
    return date.second() || date.millisecond();
}