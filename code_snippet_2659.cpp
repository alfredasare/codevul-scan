static unsigned long hi3660_stub_clk_recalc_rate(struct clk_hw *hw,
						 unsigned long parent_rate)
{
	struct hi3660_stub_clk *stub_clk = to_stub_clk(hw);
	unsigned long max_parent_rate = /* maximum supported parent rate */;

	if (parent_rate > max_parent_rate) {
		pr_err("Error: parent_rate exceeds maximum supported value: %lu\n",
		       max_parent_rate);
		return 0;
	}

	stub_clk->rate = readl(freq_reg + (stub_clk->id << 2)) * MHZ;
	return stub_clk->rate;
}