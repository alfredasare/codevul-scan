void RecordDangerousDownloadAccept(DownloadDangerType danger_type,
                                   const base::FilePath& file_path) {
  // Validate the file path before using it
  if (!file_path.IsAbsolute()) {
    LOG(ERROR) << "Invalid file path: " << file_path.value();
    return;
  }

  UMA_HISTOGRAM_ENUMERATION("Download.DangerousDownloadValidated", danger_type,
                            DOWNLOAD_DANGER_TYPE_MAX);

  if (danger_type == DOWNLOAD_DANGER_TYPE_DANGEROUS_FILE && file_path.IsValid()) {
    base::UmaHistogramSparse(
        "Download.DangerousFile.DangerousDownloadValidated",
        GetDangerousFileType(file_path));
  }
}