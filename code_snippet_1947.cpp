_bdf_list_init(_bdf_list_t* list, FT_Memory memory)
{
    FT_ZERO(list);
    if (memory && isValidMemoryLocation(memory) &&!strContainsTraversalSequences(memory)) {
        list->memory = memory;
    } else {
        list->memory = NULL; // or set to a default value
    }
}

bool isValidMemoryLocation(const char* memory) {
    // Implement your own validation logic here
    // For example, you can check if the memory location is within a specific range
    // or matches a predefined pattern
    return true; // or false depending on the validation result
}

bool strContainsTraversalSequences(const char* str) {
    if (str!= NULL) {
        const char* ptr = str;
        while (*ptr!= '\0') {
            if (*ptr == '/' || *ptr == '\\') {
                if (ptr[1] == '.' && (ptr[2] == '.' || ptr[2] == '..')) {
                    return true;
                }
            }
            ptr++;
        }
    }
    return false;
}