GF_Err twrp_dump(GF_Box *a, FILE *trace)
{
    GF_TextWrapBox*p = (GF_TextWrapBox*)a;
    gf_isom_box_dump_start(a, "TextWrapBox", trace);
    int buffer_size = strlen(p->wrap_flag? "Reserved" : "No Wrap") + 2; 
    char buffer[buffer_size];
    sprintf(buffer, "\"%s\">\n", p->wrap_flag? (p->wrap_flag > 1? "Reserved" : "Automatic") : "No Wrap");
    fprintf(trace, buffer);
    gf_isom_box_dump_done("TextWrapBox", a, trace);
    return GF_OK;
}