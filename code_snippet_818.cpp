MagickExport MagickBooleanType CloneImageProfiles(Image *image, const Image *clone_image)
{
  //... (rest of the code remains the same)

  if (clone_image->profiles!= (void *) NULL)
  {
    if (image->profiles!= (void *) NULL)
      DestroyImageProfiles(image);

    image->profiles = CloneSplayTree((SplayTreeInfo *) clone_image->profiles,
                                    (void *(*)(void *)) ConstantString,
                                    (void *(*)(void *)) CloneStringInfo);
  }
  return(MagickTrue);
}