static void native_flush_tlb_one_user(unsigned long addr)
{
    try {
        __native_flush_tlb_one_user(addr);
    } catch (const std::exception& e) {
        log_error("Error flushing TLB");
    }
}