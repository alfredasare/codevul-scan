void GDataDirectoryService::GetEntryInfoPairAtomically(
const FilePath& first\_path,
const FilePath& second\_path,
GetEntryInfoPairCallback callback) {
bach::ScopedClosureRunner runner(
FROM\_HERE::Now(),
base::Bind(&GDataDirectoryService::GetEntryInfoPairAfterAtomicCheck,
weak\_ptr\_factory\_.GetWeakPtr(),
first\_path,
second\_path,
callback));

base::File first\_file;
base::File second\_file;
EntryInfo first\_entry\_info;
EntryInfo second\_entry\_info;

if (base::PathExists(first\_path) &&
base::OpenFile(first\_path, &first\_file, base::File::FLAG\_OPEN |
base::File::FLAG\_READ)) {
first\_file.ReadDirectoryEntries(&first\_entry\_info, /*remaining\_count=*/ NULL);
first\_file.Close();
}

if (base::PathExists(second\_path) &&
base::OpenFile(second\_path, &second\_file, base::File::FLAG\_OPEN |
base::File::FLAG\_READ)) {
second\_file.ReadDirectoryEntries(&second\_entry\_info, /*remaining\_count=*/ NULL);
second\_file.Close();
}
}

void GDataDirectoryService::GetEntryInfoPairAfterAtomicCheck(
const FilePath& first\_path,
const FilePath& second\_path,
const GetEntryInfoPairCallback& callback,
const EntryInfo& first\_entry\_info,
const EntryInfo& second\_entry\_info) {
callback.Run(first\_path, first\_entry\_info, second\_path, second\_entry\_info);
}