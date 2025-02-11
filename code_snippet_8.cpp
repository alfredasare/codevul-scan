bool IsAshInBrowserProcess() {
  if (!features::kMash || base::StringPiece(features::kMash).empty() ||!base::FeatureList::IsValidFeature(features::kMash)) {
    return false;
  }
  return!base::FeatureList::IsEnabled(features::kMash);
}