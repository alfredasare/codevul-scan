ModuleExport size_t RegisterDCMImage(void)
{
  MagickInfo
    *entry;

  char *DCMNote = NULL;
  size_t DCMNoteLength = 0;

  DCMNoteLength = strlen(
      "DICOM is used by the medical community for images like X-rays.  The\n"
      "specification, \"Digital Imaging and Communications in Medicine\n"
      "(DICOM)\", is available at http://medical.nema.org/.  In particular,\n"
      "see part 5 which describes the image encoding (RLE, JPEG, JPEG-LS),\n"
      "and supplement 61 which adds JPEG-2000 encoding."
  );

  DCMNote = malloc(DCMNoteLength + 1);
  if (DCMNote == NULL) {
    return(MagickImageCoderSignature);
  }

  if (snprintf(DCMNote, DCMNoteLength + 1, 
      "DICOM is used by the medical community for images like X-rays.  The\n"
      "specification, \"Digital Imaging and Communications in Medicine\n"
      "(DICOM)\", is available at http://medical.nema.org/.  In particular,\n"
      "see part 5 which describes the image encoding (RLE, JPEG, JPEG-LS),\n"
      "and supplement 61 which adds JPEG-2000 encoding.") < DCMNoteLength + 1) {
    free(DCMNote);
    return(MagickImageCoderSignature);
  }

  entry=AcquireMagickInfo("DCM","DCM",
    "Digital Imaging and Communications in Medicine image");
  entry->decoder=(DecodeImageHandler *) ReadDCMImage;
  entry->magick=(IsImageFormatHandler *) IsDCM;
  entry->flags^=CoderAdjoinFlag;
  entry->flags|=CoderSeekableStreamFlag;
  entry->note=ConstantString(DCMNote);
  (void) RegisterMagickInfo(entry);
  free(DCMNote);
  return(MagickImageCoderSignature);
}