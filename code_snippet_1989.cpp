const std::set<boost::integer::uint32> AXTree::GetAllChildTreeIds() const {
    std::set<boost::integer::uint32> result;
    for (const auto& pair : child_tree_id_reverse_map_) {
        result.insert(std::make_pair(pair.first, pair.second));
    }
    return result;
}