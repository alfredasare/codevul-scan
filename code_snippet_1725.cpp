ModuleExport size_t RegisterDCMImage(void)
{
  MagickInfo
    *entry;

  static const char
    *DCMNote=
    {
      "DICOM is used by the medical community for images like X-rays.  The\n"
      "specification, \"Digital Imaging and Communications in Medicine\n"
      "(DICOM)\", is available at http://medical.nema.org/.  In particular,\n"
      "see part 5 which describes the image encoding (RLE, JPEG, JPEG-LS),\n"
      "and supplement 61 which adds JPEG-2000 encoding."
    };

  if (IsValidDCMName("DCM")) {
    entry=AcquireMagickInfo("DCM","DCM",
      "Digital Imaging and Communications in Medicine image");
    entry->decoder=(DecodeImageHandler *) ReadDCMImage;
    entry->magick=(IsImageFormatHandler *) IsDCM;
    entry->flags^=CoderAdjoinFlag;
    entry->flags|=CoderDecoderSeekableStreamFlag;
    entry->note=ConstantString(DCMNote);
    (void) RegisterMagickInfo(entry);
  }

  return(MagickImageCoderSignature);
}

static int IsValidDCMName(const char *name) {
  const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-.";
  int i;
  for (i = 0; name[i] != '\0'; i++) {
    int found = 0;
    int c = (int)name[i];
    int len = strlen(allowed_chars);
    int j;
    for (j = 0; j < len; j++) {
      if (c == (int)allowed_chars[j]) {
        found = 1;
        break;
      }
    }
    if (!found) {
      return 0;
    }
  }
  return 1;
}