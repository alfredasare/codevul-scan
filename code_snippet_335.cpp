GfxRadialShading::~GfxRadialShading() {
 int i;

 for (i = 0; i < nFuncs; ++i) {
 delete funcs[i];
 funcs[i] = nullptr; // Fix: Null out the pointers after deletion
 }
}