static void DebugRepaint(ttfFont *ttf) {
    if (ttf && ttf->font_data && ttf->font_data_length > 0) {
        for (int i = 0; i < ttf->font_data_length; i++) {
            // Process font data at index 'i'
        }
    } else {
        printf("Invalid or null font pointer\n");
    }
}