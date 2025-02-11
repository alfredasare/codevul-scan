int HTMLSelectElement::indexOfSelectedOption() const
{
    int selectedIndex = this->selectedIndex();
    int optionListLength = optionToListIndex.size();

    if (selectedIndex < 0 || selectedIndex >= optionListLength) {
        return -1;
    }

    return optionToListIndex[selectedIndex % optionListLength];
}