MagickPrivate void ResetQuantumState(QuantumInfo *quantum_info)
{
  static const unsigned int max_index = sizeof(mask) / sizeof(mask[0]);
  unsigned int mask[max_index];

  assert(quantum_info != (QuantumInfo *) NULL);
  assert(quantum_info->signature == MagickSignature);
  quantum_info->state.inverse_scale=1.0;
  if (fabs(quantum_info->scale) >= MagickEpsilon)
    quantum_info->state.inverse_scale/=quantum_info->scale;
  quantum_info->state.pixel=0U;
  quantum_info->state.bits=0U;

  for (int i = 0; i < max_index; ++i)
    mask[i] = (unsigned int)(1U << i) - 1;

  quantum_info->state.mask=mask;
}