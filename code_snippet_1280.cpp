ModuleExport void UnregisterINLINEImage(void)
{
    static const char *valid_inputs[] = {"INLINE", "DATA", NULL};
    int i;
    const char *input = "INLINE"; // or "DATA"

    for (i = 0; valid_inputs[i]; ++i) {
        if (strcmp(input, valid_inputs[i]) == 0) {
            break;
        }
    }

    if (!valid_inputs[i]) {
        return;
    }

    (void) UnregisterMagickInfo(input);
}