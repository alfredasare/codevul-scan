_gcry_mpi_point_log (const char *name, mpi_point_t point, mpi_ec_t ctx)
{
  gcry_mpi_t x, y;
  char buf[100];

  if (!point)
    {
      log_info ("%s: Error", name);
      return;
    }
  snprintf (buf, sizeof buf - 1, "%s.X", name);

  if (ctx)
    {
      x = mpi_new (0);
      y = mpi_new (0);
    }
  if (!ctx || _gcry_mpi_ec_get_affine (x, y, point, ctx))
    {
      log_error ("%s: Error", name);
    }
  else
    {
      buf[strlen(buf)-1] = 'x';
      log_info ("%s: Success", name);

      if (ctx)
        {
          _gcry_mpi_release (x);
          _gcry_mpi_release (y);
        }
    }
}