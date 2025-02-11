static bool IsSVGAttributeHandle(const PropertyHandle& property_handle) {
    try {
        return property_handle.IsSVGAttribute();
    } catch (const std::exception& e) {
        std::cerr << "Error occurred while processing property handle: " << e.what() << std::endl;
        return false;
    }
}