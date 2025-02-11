lzh_make_fake_table(struct huffman *hf, uint16_t c)
{
	if (!hf || !hf->tbl || c >= hf->len_size || hf->len_size <= 0 || c >= HF_TBL_SIZE) {
		fprintf(stderr, "Error: Invalid huffman structure or array index\n");
		return (0);
	}
	hf->tbl[c] = c;
	hf->max_bits = 0;
	hf->shift_bits = 0;
	hf->bitlen[hf->tbl[c]] = 0;
	return (1);
}