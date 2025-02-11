static int check_addr_less_start(RBinJavaField *method, ut64 addr) {
    ut64 start = r_bin_java_get_method_code_offset(method);
    if (addr < 0 || addr >= start + method->code_size) {
        return -1; // or some other error value
    }
    int result = (int)(addr - start);
    return result < 0;
}