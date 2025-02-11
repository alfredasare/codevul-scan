c++
bool ParamTraits<gfx::SizeF>::Read(const Message* m, PickleIterator* iter, gfx::SizeF* p) {
  float w = 0, h = 0;
  if (iter->ReadFloat(&w) && iter->ReadFloat(&h)) {
    if (w > 0 && h > 0) {
      p->set_width(w);
      p->set_height(h);
      return true;
    }
  }
  return false;
}