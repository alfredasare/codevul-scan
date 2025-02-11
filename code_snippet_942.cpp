&DownloadManagerImpl::OnHistoryNextIdRetrived,
weak\_factory_.GetWeakPtr()));
}
vbnet

The `RetrieveHistoryNextId` method checks if `is_history_download_id_retrieved_` is true and returns if it is. If not, it sets `is_history_download_id_retrieved_` to true and proceeds with retrieving the history next ID using the `delegate_` as before. This refactoring ensures that the check and retrieval are atomic, eliminating the TOCTOU race condition.