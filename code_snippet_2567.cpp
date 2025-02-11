static EAS_I16 ConvertSustain (EAS_I32 sustain)
{
 // check for sustain level of zero
 if (sustain == 0)
 return 0;

 // Ensure the result does not overflow
 if (sustain >= 0 && sustain <= INT16_MAX / SUSTAIN_LINEAR_CONVERSION_FACTOR)
 {
 // convert to log2 factor
 //lint -e{704} use shift for performance
 sustain = (sustain * SUSTAIN_LINEAR_CONVERSION_FACTOR) >> 15;
 }
 else
 {
 // Return maximum or minimum value based on the sign of sustain
 // to avoid overflow and wraparound
 sustain = (sustain > 0) ? INT16_MAX : INT16_MIN;
 }

 if (sustain > SYNTH_FULL_SCALE_EG1_GAIN)
 return SYNTH_FULL_SCALE_EG1_GAIN;
 return (EAS_I16) sustain;
}