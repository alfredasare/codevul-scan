void RecordDangerousDownloadAccept(DownloadDangerType danger_type,
                                   const base::FilePath& file_path) {
  if (danger_type < DOWNLOAD_DANGER_TYPE_MIN || danger_type > DOWNLOAD_DANGER_TYPE_MAX) {
    LOG(ERROR) << "Invalid danger type: " << danger_type;
    return;
  }

  UMA_HISTOGRAM_ENUMERATION("Download.DangerousDownloadValidated", danger_type,
                            DOWNLOAD_DANGER_TYPE_MAX);

  if (static_cast<int>(danger_type) == static_cast<int>(DOWNLOAD_DANGER_TYPE_DANGEROUS_FILE)) {
    base::UmaHistogramSparse(
        "Download.DangerousFile.DangerousDownloadValidated",
        GetDangerousFileType(file_path));
  }
}