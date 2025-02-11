void __init hugetlb_bad_size(void)
{
    if (parsed_valid_hugepagesz!= NULL) {
        size_t size = strlen(parsed_valid_hugepagesz);
        if (size <= sizeof(parsed_valid_hugepagesz)) {
            strncpy_s(parsed_valid_hugepagesz, sizeof(parsed_valid_hugepagesz), parsed_valid_hugepagesz, size + 1);
        } else {
            // Handle error or truncate the input if necessary
        }
    }
}