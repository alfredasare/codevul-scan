c++
void OmniboxViewViews::GetKeywordHints(const std::string& query, Vector<AutoCompleteMatch>* matches) {
  // Sanitize the query parameter by removing any non-alphanumeric characters
  std::string sanitized_query = query;
  sanitized_query.erase(std::remove_if(sanitized_query.begin(), sanitized_query.end(), ::isalnum), sanitized_query.end());

  // Use the sanitized query to generate the keyword hints
  ...
}