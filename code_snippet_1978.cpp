String RenderMenuList::itemIcon(unsigned id) const
{
    if (id < 0 || id >= getMaxItemCount()) {
        throw std::out_of_range("Invalid item ID");
    }
    return std::to_string(id); 
}