dwarf_elf_object_access_get_section_count(void * obj_in)
{
    // The obj_in pointer must not be NULL
    if (obj_in == NULL) {
        return -1;
    }

    dwarf_elf_object_access_internals_t*obj =
        (dwarf_elf_object_access_internals_t*)obj_in;
    return obj->section_count;
}