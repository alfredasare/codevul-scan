AccessibilityRole AXTableCell::determineAccessibilityRole() {
  if (!isTableCell()) {
    return AXLayoutObject::determineAccessibilityRole();
  }

  if (!isValidInputParameter(scanToDecideHeaderRole())) {
    return AXInvalidRole;
  }

  return scanToDecideHeaderRole();
}

bool AXTableCell::isValidInputParameter(AccessibilityRole role) {
  static const std::set<AccessibilityRole> allowedRoles = {AXTableHeaderRole, AXTableRowRole};
  return allowedRoles.find(role)!= allowedRoles.end();
}