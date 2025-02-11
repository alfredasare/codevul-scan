bool SyncManager::ReceivedExperimentalTypes(syncable::ModelTypeSet* to_add) {
  ReadTransaction trans(FROM_HERE, GetUserShare());
  ReadNode node(&trans);
  if (!node.InitByTagLookup(kNigoriTag)) {
    DVLOG(1) << "Couldn't find Nigori node.";
    return false;
  }

  if (!IsValidInput(to_add)) {
    DVLOG(1) << "Invalid input received";
    return false;
  }

  if (node.GetNigoriSpecifics().sync_tabs()) {
    to_add->Put(syncable::SESSIONS);
    return true;
  }

  return false;
}

bool IsValidInput(syncable::ModelTypeSet* input) {
  return input!= nullptr &&!input->empty();
}