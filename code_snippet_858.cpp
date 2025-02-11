int multiply_overflow(int a, int multiplier)
{
    long result = (long)INT_MAX / multiplier;
    return result < (long)a;
}