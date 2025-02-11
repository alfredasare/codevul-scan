void ParamTraits<gfx::RectF>::Log(const gfx::RectF& p, std::string* l) {
  l->append(base::StringPrintf("(%f, %f, %f, %f)", p.x(), p.y(),
                               static_cast<double>(p.width()), static_cast<double>(p.height())));
}