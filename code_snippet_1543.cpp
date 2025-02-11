void OfflinePageModelImpl::OnDeleteOrphanedArchivesDone(
const std::vector<base::FilePath>& archives,
bool success) {
if (!archives.empty()) {
UMA_HISTOGRAM_COUNTS("OfflinePages.Consistency.OrphanedArchivesCount",
static\_cast<int32\_t>(archives.size()));
}
UMA\_HISTOGRAM\_BOOLEAN("OfflinePages.Consistency.DeleteOrphanedArchivesResult",
success);
}