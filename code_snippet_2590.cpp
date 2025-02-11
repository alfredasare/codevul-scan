static void ToColor_S32_Alpha(SkColor dst[], const void* src, int width, SkColorTable*) {
    SkASSERT(width > 0 && width <= SkColorBytes(SkColorType::kN32_SkColorType)/sizeof(SkPMColor));
    const SkPMColor* s = (const SkPMColor*)src;
    for (int i = 0; i < width; ++i) {
        *dst++ = SkUnPreMultiply::PMColorToColor(*s++);
    }
}