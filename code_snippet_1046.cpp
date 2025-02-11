c++
const int NUM_CONTENT_RESTRICTIONS = 8; // or the appropriate number

void Browser::UpdateCommandsForContentRestrictionState() {
  int restrictions = GetContentRestrictionsForSelectedTab();

  // Check that the value of restrictions is within the expected range
  if (restrictions < 0 || restrictions >= NUM_CONTENT_RESTRICTIONS) {
    // Handle the error case where restrictions is out of bounds
    // ...
    return;
  }

  command_updater_.UpdateCommandEnabled(
      IDC_COPY, !(restrictions & CONTENT_RESTRICTION_COPY));
  command_updater_.UpdateCommandEnabled(
      IDC_CUT, !(restrictions & CONTENT_RESTRICTION_CUT));
  command_updater_.UpdateCommandEnabled(
      IDC_PASTE, !(restrictions & CONTENT_RESTRICTION_PASTE));
  UpdateSaveAsState(restrictions);
  UpdatePrintingState(restrictions);
}