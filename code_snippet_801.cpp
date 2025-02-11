ZEND_API size_t zend_memory_peak_usage(int real_usage) {
#if ZEND_MM_STAT
    if (real_usage) {
        return (size_t)AG(mm_heap)->real_peak; 
    } else {
        return (size_t)AG(mm_heap)->peak; 
    }
#endif
    return 0;
}