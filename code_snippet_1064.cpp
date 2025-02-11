Here's the fixed version of the function using the provided recommendations:


static u64 muldiv64_fixed(u64 a, u32 b, u32 c)
{
	u64 res_high, res_low;

	if (umul64_fixed(a, b, &res_high, &res_low)) {
		return 0; // Or any other appropriate error handling
	}

	return div64_u64(res_high, c) * (u64)0x100000000 + div64_u64(res_low, c);
}

static bool umul64_fixed(u64 a, u32 b, u64* res_high, u6