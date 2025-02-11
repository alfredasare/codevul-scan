void Gfx::opSetFont(Object args[], int numArgs) {
  GfxFont *font;

  if (numArgs < 2 ||!args[0].getName() ||!args[1].getNum()) {
    state->setFont(NULL, 0);
    fontChanged = gTrue;
    return;
  }

  const char *fontName = args[0].getName()->getCString();
  if (!isValidFontName(fontName)) {
    state->setFont(NULL, 0);
    fontChanged = gTrue;
    return;
  }

  font = res->lookupFont(args[0].getName());
  if (!font) {
    state->setFont(NULL, 0);
    fontChanged = gTrue;
    return;
  }

  if (printCommands) {
    printf("  font: tag=%s name='%s' %g\n",
           font->getTag()->getCString(),
           font->getName()? font->getName()->getCString() : "???",
           args[1].getNum());
    fflush(stdout);
  }

  font->incRefCnt();
  state->setFont(font, args[1].getNum());
  fontChanged = gTrue;
}