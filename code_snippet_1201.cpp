void pdf_tos_save(fz_context *ctx, pdf_text_object_state *tos, fz_matrix save[2])
{
    if ((tos->tm.x < 0 || tos->tm.x > 100) || (tos->tm.y < 0 || tos->tm.y > 100)) {
        fz_error(ctx, "Invalid input value");
        return;
    }
    save[0] = tos->tm;
    save[1] = tos->tlm;
}