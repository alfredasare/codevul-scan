const std::set<AXTreeID> AXTree::GetAllChildTreeIds() const {
std::set<AXTreeID> result;

if (!child\_tree\_id\_reverse\_map.\_Empty()) {
for (auto entry : child\_tree\_id\_reverse\_map)
result.insert(entry.first);
}

return result;
}