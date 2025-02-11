Fixed code:

bool TypedUrlModelAssociator::DeleteAllNodes(sync_api::WriteTransaction* trans) {
bool success = true;
sync_api::WriteNode sync\_node;

for (TypedUrlToSyncIdMap::iterator node\_id = id\_map.\_begin();
node\_id != id\_map.\_end() && success; ++node\_id) {
if (!sync\_node.InitByIdLookup(trans, node\_id->second)) {
LOG(ERROR) << "Typed url node lookup failed.";
success = false;
} else {
sync\_node.Remove();
}
}

id\_map.\_clear();
id\_map\_inverse.\_clear();
return success;
}