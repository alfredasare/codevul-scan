static PassRefPtr<CSSValue> valueForNinePieceImage(const NinePieceImage& image)
{
    if (!image.hasImage() || !image.image() || !image.borderSlices() || !image.outset() || !image.repeat())
        return cssValuePool().createIdentifierValue(CSSValueNone);

    RefPtr<CSSValue> imageValue = image.image()->cssValue();
    RefPtr<CSSBorderImageSliceValue> imageSlices = valueForNinePieceImageSlice(image);
    RefPtr<CSSValue> borderSlices = valueForNinePieceImageQuad(image.borderSlices());
    RefPtr<CSSValue> outset = valueForNinePieceImageQuad(image.outset());
    RefPtr<CSSValue> repeat = valueForNinePieceImageRepeat(image);

    return createBorderImageValue(imageValue, imageSlices, borderSlices, outset, repeat);
}