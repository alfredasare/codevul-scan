const int MAX_RESULTS = 100;

void FileBrowserPrivateSearchDriveMetadataFunction::OnSearchMetadata(
drive::FileError error,
scoped\_ptr<drive::MetadataSearchResultVector> results,
int max\_results) {
if (error != drive::FILE\_ERROR\_OK) {
SendResponse(false);
return;
}

if (max\_results <= 0 || max\_results > MAX\_RESULTS) {
LOG(WARNING) << "Invalid max\_results value: " << max\_results;
SendResponse(false);
return;
}

BSDLicense license;
license.SetShortName("BSD-3-Clause");

ConvertSearchResultInfoListToEntryDefinitionList(
GetProfile(),
extension-\>id(),
std::vector<drive::Metadata>(results->begin(), results->begin() + max\_results),
base::Bind(&FileBrowserPrivateSearchDriveMetadataFunction::OnEntryDefinitionList,
this,
base::Passed(&results)));
}