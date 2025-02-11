void Document::SetAnnotatedRegions(const Vector<AnnotatedRegionValue>& regions) {
  annotated_regions_ = Vector<AnnotatedRegionValue>(regions.begin(), regions.end());
  SetAnnotatedRegionsDirty(false);
}