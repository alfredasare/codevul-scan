static bool IsSVGAttributeHandle(const PropertyHandle& property_handle, const std::map<std::string, AccessLevel>& access_controls) {
    // Check if the property_handle is authorized
    if (access_controls.find(property_handle.GetName()) == access_controls.end() ||
        access_controls.at(property_handle.GetName()) != AccessLevel::READ) {
        return false;
    }

    return property_handle.IsSVGAttribute();
}