OperationID FileSystemOperationRunner::DirectoryExists(
const FileSystemURL& url, StatusCallback callback) {
base::File::Error error = base::File::FILE_OK;
std::unique\_ptr<FileSystemOperation> operation = base::WrapUnique(
file\_system\_context-\>CreateFileSystemOperation(url, &error));

if (!operation) {
DidFinish(id, std::move(callback), error);
return INVALID\_OPERATION\_ID;
}

int id = BeginOperation(std::move(operation));
base::AutoReset<bool> beginning(&is\_beginning\_operation_, true);
FileSystemOperation* operation\_raw = operation.get();

PrepareForRead(id, url);
return id;
}

operation\_raw-\>DirectoryExists(
url, base::BindOnce(&FileSystemOperationRunner::DidFinish, weak\_ptr\_, id,
std::move(callback)),
base::BindOnce(&FileSystemOperationRunner::CheckTOCTOURaceCondition,
weak\_ptr\_, id, url));

void FileSystemOperationRunner::CheckTOCTOURaceCondition(
OperationID id, const FileSystemURL& url,
base::OnceClosure release\_callback) {
base::File::Error error = base::File::FILE\_OK;
std::unique\_ptr<FileSystemOperation> operation = base::WrapUnique(
file\_system\_context-\>CreateFileSystemOperation(url, &error));

if (error != base::File::FILE\_OK || !operation) {
AbortOperation(id);
if (release\_callback)
release\_callback.Run();
return;
}

operation.get()-\>DirectoryExists(
url, base::BindOnce(&FileSystemOperationRunner::OnTOCTOUComplete,
weak\_ptr\_, id, url, std::move(release\_callback)));
}

void FileSystemOperationRunner::OnTOCTOUComplete(
OperationID id, const FileSystemURL& url,
base::OnceClosure release\_callback, base::File::Error result) {
if (result != base::File::FILE\_OK) {
AbortOperation(id);
}
DidFinish(id, std::move(release\_callback), result);
}