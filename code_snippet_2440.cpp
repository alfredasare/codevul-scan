enum TableInitState {
    TABLE_UNINITIALIZED = 0,
    TABLE_INITIALIZED = 0xDEADBEEFUL
};

PS_Table_release(PS_Table table)
{
    FT_Memory memory = table->memory;

    if (table->init == TABLE_INITIALIZED)
    {
        FT_FREE(table->block);
        FT_FREE(table->elements);
        FT_FREE(table->lengths);
        table->init = TABLE_UNINITIALIZED;
    }
}