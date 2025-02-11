#include <linux/mmzone.h>
#include <linux/hugetlb.h>

void hugetlb_good_size(void)
{
	if (huge_page_order > MAX_ORDER || huge_page_order < 0) {
		pr_err("Invalid hugepage order: %d\n", huge_page_order);
		return;
	}

	parsed_valid_hugepagesz = true;
}