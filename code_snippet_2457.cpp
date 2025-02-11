midi_data_reassemble_init(void)
{
    // Update the library to a patched version
    reassembly_table_functions_t* patched_functions = &patched_addresses_reassembly_table_functions_v2_1_0;
    reassembly_table_init(&midi_data_reassembly_table, patched_functions);
}