dwarf_elf_object_access_get_section_count(void * obj_in)
{
    dwarf_elf_object_access_internals_t*obj = (dwarf_elf_object_access_internals_t*)obj_in;

    // Validate section_count
    if (obj->section_count < 0 || obj->section_count > MAX_SECTION_COUNT) {
        return -1; // or some other error value
    }

    return obj->section_count;
}