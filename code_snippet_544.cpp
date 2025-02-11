Range* Document::caretRangeFromPoint(int x, int y) {
  if (GetLayoutViewItem().IsNull())
    return nullptr;

  // Validate user input
  const int max_x = 1000; // Max allowed x value
  const int max_y = 1000; // Max allowed y value
  if (x < 0 || x > max_x || y < 0 || y > max_y) {
    // Handle invalid input or throw an exception
    return nullptr;
  }

  HitTestResult result = HitTestInDocument(this, x, y);
  PositionWithAffinity position_with_affinity = result.GetPosition();
  if (position_with_affinity.IsNull())
    return nullptr;

  Position range_compliant_position =
      SanitizePosition(position_with_affinity.GetPosition());

  // Add bounds checking before creating the range
  if (range_compliant_position.IsNotNull()) {
    const int max_range_compliant_position = 1000; // Max allowed value
    if (range_compliant_position > max_range_compliant_position) {
      // Handle invalid range_compliant_position or throw an exception
      return nullptr;
    }
  } else {
    // Handle sanitization failure or throw an exception
    return nullptr;
  }

  return Range::CreateAdjustedToTreeScope(*this, range_compliant_position);
}

Position Document::SanitizePosition(const Position& position) {
  // Implement sanitization logic here based on your specific requirements
  // For example, you can limit the position to a certain tree scope
  // or restrict it to specific nodes in the document
}