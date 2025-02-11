static bool signed_sub_overflows(s64 a, s64 b)
{
	if ((a > 0 && b < 0 && (s64)((u64)a + (u64)(-b) < (u64)a)) ||
	    (a < 0 && b > 0 && (s64)((u64)a + (u64)(-b) > (u64)a)))
		return true;
	return false;
}