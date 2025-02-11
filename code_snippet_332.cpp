GfxRadialShading::~GfxRadialShading() {
  if (funcs) {
    for (int i = 0; i < nFuncs; ++i) {
      if (funcs[i]) {
        delete funcs[i];
      }
    }
    delete[] funcs;
  }
}