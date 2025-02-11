void OfflinePageModelImpl::OnDeleteOrphanedArchivesDone(
    const std::vector<base::FilePath>& archives,
    bool success) {
  const int32_t maxHistogramValue = 100; // adjust according to your requirements
  int32_t histogramValue = std::min(static_cast<int32_t>(std::min(archives.size(), maxHistogramValue)), maxHistogramValue);
  UMA_HISTOGRAM_COUNTS("OfflinePages.Consistency.OrphanedArchivesCount", histogramValue);
  UMA_HISTOGRAM_BOOLEAN("OfflinePages.Consistency.DeleteOrphanedArchivesResult", success);
}