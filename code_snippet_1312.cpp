c++
void FileBrowserPrivateSearchDriveMetadataFunction::OnSearchMetadata(
    drive::FileError error,
    scoped_ptr<drive::MetadataSearchResultVector> results) {
  if (error!= drive::FILE_ERROR_OK) {
    SendResponse(false);
    return;
  }

  DCHECK(results.get());
  const drive::MetadataSearchResultVector& results_ref = *results.get();

  // Validate input data
  if (!results_ref.IsValid()) {
    SendResponse(false);
    return;
  }

  // Use secure string manipulation
  base::FilePath search_path = base::PathAppend(base::FilePath::kBaseDir, results_ref.GetString());
  if (!base::PathIsSafe(search_path)) {
    SendResponse(false);
    return;
  }

  ConvertSearchResultInfoListToEntryDefinitionList(
      GetProfile(),
      extension_->id(),
      results_ref,
      base::Bind(
          &FileBrowserPrivateSearchDriveMetadataFunction::OnEntryDefinitionList,
          this,
          base::Passed(&results)));
}