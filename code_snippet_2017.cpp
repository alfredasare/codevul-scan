static inline void ModulateHSV(const double percent_hue,
  const double percent_saturation,const double percent_value,double *red,
  double *green,double *blue)
{
  double
    hue,
    saturation,
    value;

  hue = fmod(hue + 0.5*(0.01*percent_hue-1.0), 1.0);
  if (hue < 0.0) {
    hue += 1.0;
  }

  saturation = fmin(fmax(saturation * 0.01*percent_saturation, 0.0), 1.0);
  value = fmin(fmax(value * 0.01*percent_value, 0.0), 1.0);

  ConvertHSVToRGB(hue,saturation,value,red,green,blue);
}