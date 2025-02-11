t42_parser_done(T42_Parser parser)
{
    FT_Memory memory = parser->root.memory;

    /* free the base dictionary only when we have a disk stream */
    if (parser->in_memory && parser->base_dict) {
        FT_FREE(parser->base_dict);
    }

    parser->root.funcs.done(&parser->root);
}