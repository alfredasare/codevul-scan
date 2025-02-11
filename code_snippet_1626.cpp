bool TypedUrlModelAssociator::DeleteAllNodes(sync_api::WriteTransaction* trans) {
  DCHECK(expected_loop_ == MessageLoop::current());
  for (const auto& pair : id_map_) {
    sync_api::WriteNode sync_node(trans);
    if (!sync_node.InitByIdLookup(pair.second)) {
      LOG(ERROR) << "Typed url node lookup failed.";
      return false;
    }
    sync_node.Remove();
  }

  id_map_.clear();
  id_map_inverse_.clear();
  return true;
}