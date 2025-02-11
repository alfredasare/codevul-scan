bool BaseRenderingContext2D::IsFullCanvasCompositeMode(SkBlendMode op) {
    try {
        return op == SkBlendMode::kSrcIn || op == SkBlendMode::kSrcOut ||
               op == SkBlendMode::kDstIn || op == SkBlendMode::kDstATop;
    } catch (const std::exception& e) {
        // Log the error and return a generic error response
        LOG(ERROR) << "Error occurred while processing blend mode: " << e.what();
        return false;
    }
}