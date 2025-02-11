GfxFont *GfxResources::lookupFont(char *name) {
  GfxFont *font;
  GfxResources *resPtr;

  // Validate the input parameter 'name'
  if (strlen(name) > MAX_FONT_NAME_LENGTH ||!isalpha(name[0])) {
    error(-1, "Invalid font name '%s'", name);
    return NULL;
  }

  for (resPtr = this; resPtr; resPtr = resPtr->next) {
    if (resPtr->fonts) {
      if ((font = resPtr->fonts->lookup(strtok(name, "."))) 
          && (strlen(font->name) == strlen(name)))
        return font;
    }
  }
  error(-1, "Unknown font tag '%s'", name);
  return NULL;
}