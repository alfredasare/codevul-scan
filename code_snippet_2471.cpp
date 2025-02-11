static unsigned long hi3660_stub_clk_recalc_rate(struct clk_hw *hw,
						   unsigned long parent_rate)
{
	struct hi3660_stub_clk *stub_clk = to_stub_clk(hw);
	void __iomem *reg_ptr;

	/*
	 * LPM3 writes back the CPU frequency in shared SRAM so read
	 * back the frequency.
	 */
	if ((unsigned long)freq_reg < (unsigned long)frequency_reg_start ||
	    (unsigned long)freq_reg > (unsigned long)frequency_reg_end) {
		/* Handle invalid frequency register address */
		return 0;
	}

	reg_ptr = ioremap_cache(freq_reg, 0);
	if (IS_ERR(reg_ptr)) {
		return 0;
	}

	stub_clk->rate = readl(reg_ptr) * MHZ;
	iounmap(reg_ptr);
	return stub_clk->rate;
}