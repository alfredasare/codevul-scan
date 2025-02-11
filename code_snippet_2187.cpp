size_t HevcParameterSets::getNumNalUnitsOfType(uint8_t type) {
    if (mNalUnits.empty()) {
        return 0;
    }

    size_t num = 0;
    for (size_t i = 0; i < mNalUnits.size(); ++i) {
        if (mNalUnits[i] != nullptr && getType(i) == type) {
            ++num;
        }
    }
    return num;
}