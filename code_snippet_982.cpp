int multiply_overflow(int a, int multiplier)
{
	if ((a > 0 && multiplier > (INT_MAX / a)) || multiplier > 1 && a > INT\_MAX / multiplier) {
		return 1;
	}
	return 0;
}