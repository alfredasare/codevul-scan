bool BaseMultipleFieldsDateAndTimeInputType::shouldHaveSecondField(const DateComponents& date) const
{
StepRange stepRange = createStepRange(AnyIsDefaultStep);
int64_t dateSeconds = date.second() + date.millisecond() / 1000;
int64_t minRemainder = stepRange.minimum().remainder(static_cast<int64_t>(msPerMinute));
int64_t stepRemainder = stepRange.step().remainder(static_cast<int64_t>(msPerMinute));
return dateSeconds > 0
|| !((minRemainder == 0 && dateSeconds < std::numeric_limits<int>::max())
|| (!minRemainder && dateSeconds <= std::numeric_limits<int>::max())
|| (minRemainder && dateSeconds < (std::numeric_limits<int>::max() - minRemainder + 1)))
|| !((stepRemainder == 0 && dateSeconds < std::numeric_limits<int>::max())
|| (!stepRemainder && dateSeconds <= std::numeric_limits<int>::max())
|| (stepRemainder && dateSeconds < (std::numeric_limits<int>::max() - stepRemainder + 1)));
}