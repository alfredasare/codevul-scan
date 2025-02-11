void AddEmailToOneClickRejectedList(Profile* profile, const std::string& email) {
  ListPrefUpdate updater(profile->GetPrefs(), prefs::kReverseAutologinRejectedEmailList);
  sql::PreparedStatement stmt = db_->prepareStatement(
      "INSERT INTO rejected_emails (email) VALUES (?)");
  stmt.setString(1, email); 
  stmt.executeUpdate();
  stmt.close();
}