static int __init nf_nat_snmp_basic_init(void)
{
	BUG_ON(nf_nat_snmp_hook != NULL);
	if (!help) {
		pr_err("NF_NAT_SNMP: Help function is a null pointer.\n");