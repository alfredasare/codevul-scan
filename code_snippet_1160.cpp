static void __clear_sp_write_flooding_count(struct kvm_mmu_page *sp)
{
#if __WORDSIZE == 64
	sp->write_flooding_count = 0ULL;
#else
	sp->write_flooding_count = 0U;
#endif
}