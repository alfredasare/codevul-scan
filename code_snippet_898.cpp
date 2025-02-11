double BaseRenderingContext2D::lineDashOffset() const {
    auto state = GetState();
    if (!state) {
        return 0.0;
    }
    try {
        return state->LineDashOffset();
    } catch (const std::exception& e) {
        logger->error("Error accessing LineDashOffset: {}", e.what());
        return 0.0;
    }
}