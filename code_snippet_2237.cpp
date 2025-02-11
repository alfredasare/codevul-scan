int midi_data_reassemble_init(void)
{
    if (reassembly_table_init(&midi_data_reassembly_table, &addresses_reassembly_table_functions) != 0)
    {
        return -1;
    }
    return 0;
}