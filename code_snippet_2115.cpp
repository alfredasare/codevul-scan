MagickPrivate void ResetQuantumState(QuantumInfo *quantum_info)
{
  static const unsigned int mask[32] =
  {
    // ...
  };

  assert(quantum_info != (QuantumInfo *) NULL);
  assert(quantum_info->signature == MagickSignature);
  quantum_info->state.inverse_scale=1.0;
  if (fabs(quantum_info->scale) >= MagickEpsilon)
  {
    if (quantum_info->scale == 0.0)
    {
      quantum_info->state.inverse_scale = 1.0; // Set a default value
    }
    else
    {
      quantum_info->state.inverse_scale /= quantum_info->scale;
    }
  }
  quantum_info->state.pixel=0U;
  quantum_info->state.bits=0U;
  quantum_info->state.mask=mask;
}