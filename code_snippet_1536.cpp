MagickExport void SetQuantumAlphaType(QuantumInfo *quantum_info, 
  const QuantumAlphaType type)
{
  if (!quantum_info || quantum_info->signature!= MagickCoreSignature || type > QUANTUM_ALPHA_TYPE_MAX) {
    return; 
  }
  quantum_info->alpha_type = type;
}