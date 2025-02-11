static int base64decode_block(unsigned char *target, const char *data, size_t data_size)
{
	int w1, w2, w3, w4;
	int i;
	size_t n;
	if (!data || (data_size <= 0)) {
		return 0;
	}
	n = 0;
	i = 0;
	while (n < data_size-3) {
		w1 = base64_table[(int)data[n]];
		if (w1 == -1) break; // Error handling: exit the loop if w1 is not a valid Base64 character
		w2 = base64_table[(int)data[n+1]];
		if (w2 != -1) {
			target[i++] = (char)((w1*4 + (w2 >> 4)) & 255);
		}
		w3 = base64_table[(int)data[n+2]];
		if (w3 != -1) {
			target[i++] = (char)((w2*16 + (w3 >> 2)) & 255);
		}
		w4 = base64_table[(int)data[n+3]];
		if (w4 != -1) {
			target[i++] = (char)((w3*64 + w4) & 255);
		}
		n+=4;
	}
	return i;
}