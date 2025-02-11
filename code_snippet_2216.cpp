void ps_table_release(PS_Table* table)
{
    FT_Memory* memory = table->memory;

    if (table->init < 0 || table->init > 0xFFFFFFFF)
    {
        return;
    }

    if (table->block && table->elements && table->lengths)
    {
        FT_Free(table->block);
        FT_Free(table->elements);
        FT_Free(table->lengths);
    }

    table->init = 0;
}