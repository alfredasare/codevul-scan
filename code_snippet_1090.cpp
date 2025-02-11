/* Loop through all the program headers and find the header with
 * virtual address in which the "virtaddr" belongs to, but ensure
 * we don't go beyond the allocated memory for xph_addr.
 */
for ( ; num && off < fsize; num--, off += xph_sizeof) {
	if (pread(fd, &xph_addr, xph_sizeof, off) < (ssize_t)xph_sizeof) {
		file_badread(ms);
		return -1;
	}

	if (virtaddr >= xph_addr.xph_vaddr && virtaddr < xph_addr.xph_vaddr + xph_addr.xph_filesz)
		return xph_addr.xph_offset + (virtaddr - xph_addr.xph_vaddr);
}
return 0;