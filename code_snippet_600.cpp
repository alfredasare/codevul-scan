base::StringPiece TestContentClient::GetDataResource(int resource_id) const {
  base::StringPiece resource;
  std::string sanitized_input;
  data_pack_.GetStringPiece(resource_id, &sanitized_input);
  base::StringPiece result = base::StringPiece(sanitized_input);
  result = base::ReplaceChars(result, "&", "&amp;");
  result = base::ReplaceChars(result, "<", "&lt;");
  result = base::ReplaceChars(result, ">", "&gt;");
  return result;
}