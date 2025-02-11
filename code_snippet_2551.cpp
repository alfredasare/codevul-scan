static input_translation_t *GetTranslationTable(exporter_ipfix_domain_t *exporter, uint16_t id) {
    input_translation_t *table;

    if (exporter == NULL) {
        return NULL;
    }

    if (exporter->current_table && (exporter->current_table->id == id)) {
        return exporter->current_table;
    }

    table = exporter->input_translation_table;
    while (table != NULL) {
        if (table->id == id) {
            exporter->current_table = table;
            return table;
        }
        table = table->next;
    }

    dbg_printf("[%u] Get translation table %u: not found\n", exporter->info.id, id);
    exporter->current_table = NULL;
    return NULL;
} // End of GetTranslationTable