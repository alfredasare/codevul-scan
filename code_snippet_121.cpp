AccessibilityRole AXTableCell::determineAccessibilityRole() {
  if (!this) {
    return AXLayoutObject::kUnknownRole;
  }

  if (!isTableCell())
    return AXLayoutObject::determineAccessibilityRole();

  return scanToDecideHeaderRole();
}