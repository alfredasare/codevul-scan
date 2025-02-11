void Document::SetAnnotatedRegions(const Vector<AnnotatedRegionValue>& regions) {
  if (regions.empty()) {
    return;
  }

  vector<AnnotatedRegionValue> sanitizedRegions;
  for (const auto& region : regions) {
    if (IsValidAnnotatedRegionValue(region)) {
      sanitizedRegions.push_back(region);
    }
  }

  annotated_regions_ = sanitizedRegions;
  SetAnnotatedRegionsDirty(false);
}

bool IsValidAnnotatedRegionValue(const AnnotatedRegionValue& value) {
  // Implement your custom validation logic here
  // For example, you can check if the value contains only allowed characters
  // or if it matches a specific pattern
  return true; // Replace with your actual validation logic
}