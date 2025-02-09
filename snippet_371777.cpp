MagickExport void ConvertLCHuvToRGB(const double luma,const double chroma,
  const double hue,Quantum *red,Quantum *green,Quantum *blue)
{
  double
    X,
    Y,
    Z;

  /*
   Convert LCHuv to RGB colorspace.
 */
  assert(red != (Quantum *) NULL);
  assert(green != (Quantum *) NULL);
  assert(blue != (Quantum *) NULL);
  ConvertLCHuvToXYZ(100.0*luma,255.0*(chroma-0.5),360.0*hue,&X,&Y,&Z);
  ConvertXYZToRGB(X,Y,Z,red,green,blue);
}