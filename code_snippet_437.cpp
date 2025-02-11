static void nfs_set_pageerror(struct page *page)
{
	struct file_mapping *file_mapping = page_file_mapping(page);
	if (file_mapping) {
		nfs_zap_mapping(file_mapping->host, file_mapping);
	}
}