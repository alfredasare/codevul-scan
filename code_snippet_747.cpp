base::StringPiece TestContentClient::GetDataResource(int resource_id) const {
  std::string resource;
  data_pack_.GetStringPiece(resource_id, &resource);
  return resource;
}