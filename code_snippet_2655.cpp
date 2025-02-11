static int getPremulBitmapCreateFlags(bool isMutable) {
int flags = GraphicsJNI::kBitmapCreateFlag\_Premultiplied;
if (isMutable && isMutable == true) {
flags |= GraphicsJNI::kBitmapCreateFlag\_Mutable;
}
return flags;
}