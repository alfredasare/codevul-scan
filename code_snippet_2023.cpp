poppler_rectangle_copy (PopplerRectangle *rectangle)
{
  PopplerRectangle *new_rectangle;

  g_return_val_if_fail (rectangle != NULL, NULL);

  new_rectangle = g_new (PopplerRectangle, 1);
  if (rectangle == NULL) {
      g_warning ("The input rectangle is a null pointer");
      g_free(new_rectangle);
      return NULL;
  }

  *new_rectangle = *rectangle;

  return new_rectangle;
}