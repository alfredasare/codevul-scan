bool SyncManager::ReceivedExperimentalTypes(syncable::ModelTypeSet* to_add) const {
  ReadTransaction trans(FROM_HERE, GetUserShare());
  ReadNode node(&trans);
  if (!node.InitByTagLookup(kNigoriTag)) {
    DVLOG(1) << "Couldn't find Nigori node.";
    return false;
  }

  const int max_type = syncable::MODEL_TYPE_COUNT - 1;
  if (node.GetNigoriSpecifics().sync_tabs() && node.GetNigoriSpecifics().type() > 0 && node.GetNigoriSpecifics().type() <= max_type) {
    to_add->Put(node.GetNigoriSpecifics().type());
    return true;
  }
  return false;
}