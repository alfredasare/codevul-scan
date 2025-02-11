code:


static EAS_I16 ConvertSustain(EAS_I32 sustain)
{
    /* check for sustain level of zero */
    if (sustain == 0)
        return 0;

    /* check for potential overflow before multiplication */
    if (sustain > (EAS_I32)INT_MAX / SUSTAIN_LINEAR_CONVERSION_FACTOR)
        return SYNTH_FULL_SCALE_EG1_GAIN;

    /* convert to log2 factor using a safe conversion method */
    EAS_I32 result = (EAS_I32)(sustain * SUSTAIN_LINEAR_CONVERSION_FACTOR);
    if (result > (EAS_I32)INT_MAX)
        result = (EAS_I32)INT_MAX;
    sustain = (EAS_I16)result;

    if (sustain > SYNTH_FULL_SCALE_EG1_GAIN)
        return SYNTH_FULL_SCALE_EG1_GAIN;
    return sustain;
}