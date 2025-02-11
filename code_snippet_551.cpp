void Compositor::OnFirstSurfaceActivation(const viz::SurfaceInfo& surface_info) {
    // Validate the input surface_info parameter
    if (surface_info.size() > kMaxSurfaceInfoSize) {
        throw std::runtime_error("Invalid surface info size");
    }

    // Check for null or invalid pointers
    if (!surface_info.GetPointer()) {
        throw std::invalid_argument("Invalid surface info pointer");
    }

    // Continue with the processing of the surface_info parameter
    //...
}