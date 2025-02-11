MagickExport void SetQuantumAlphaType(QuantumInfo *quantum_info,
                                       const QuantumAlphaType type)
{
  if (quantum_info == NULL)
  {
    /* Handle error */
    return;
  }
  
  assert(quantum_info->signature == MagickCoreSignature);
  quantum_info->alpha_type=type;
}