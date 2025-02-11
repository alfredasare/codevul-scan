c++
void AutofillDialogViews::UpdateSection(DialogSection section) {
  if (section >= DialogSection::MIN_VALUE && section <= DialogSection::MAX_VALUE) {
    UpdateSectionImpl(section, true);
  }
}