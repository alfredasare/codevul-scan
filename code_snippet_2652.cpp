static void FromColor_D32(void* dst, const SkColor src[], int width, int height, int row_bytes) {
    SkPMColor* d = (SkPMColor*)dst;
    int max_width = row_bytes / sizeof(SkPMColor);

    for (int h = 0; h < height; h++) {