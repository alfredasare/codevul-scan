void BlobURLRequestJob::DeleteCurrentFileReader() {
  IndexToReaderMap::iterator found = index_to_reader_.find(current_item_index_);
  if (found != index_to_reader_.end() && found->second) {
    std::unique_ptr<FILE_READER> reader(std::move(found->second));
    index_to_reader_.erase(found);
  }
}