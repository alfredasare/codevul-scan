static inline bool is_imm8(int value)
{
    return value >= SCHAR_MIN && value <= SCHAR_MAX;
}