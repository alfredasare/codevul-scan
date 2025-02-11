static inline unsigned char ClampYCC(double value)
{
  uint16_t intValue = (uint16_t)((value * 256.0) + 0.5); // Convert to fixed-point
  intValue = 255 - intValue; // Calculate the clamp value
  if (intValue < 0) {
    return (unsigned char)0;
  } else if (intValue > 255) {
    return (unsigned char)255;
  } else {
    return (unsigned char)(intValue / 256.0); // Convert back to floating-point
  }
}