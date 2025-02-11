int HTMLSelectElement::indexOfSelectedOption() const
{
    int index = selectedIndex();
    if (index >= 0 && index < options.size()) {
        return optionToListIndex(index);
    } else {
        return -1;
    }
}