void ParamTraits<gfx::RectF>::Log(const gfx::RectF& p, std::string* l) {
l->append(base::StringPrintf("(%.2f, %.2f, %.2f, %.2f)", p.x(), p.y(),
                           std::min(p.width(), static_cast<float>(std::numeric_limits<double>::max() - std::numeric_limits<double>::max() / 2)),
                           std::min(p.height(), static_cast<float>(std::numeric_limits<double>::max() - std::numeric_limits<double>::max() / 2))));
}