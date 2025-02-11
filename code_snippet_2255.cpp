ec_get_a_is_pminus3 (mpi_ec_t ec)
{
  gcry_mpi_t tmp;
  int err = 0;

  if (!ec->t.valid.a_is_pminus3)
    {
      ec->t.valid.a_is_pminus3 = 1;
      tmp = mpi_alloc_like (ec->p);
      if (tmp == NULL)
        {
          gcry_error();
          gcry_exception(err, "Error allocating memory");
          return 0;
        }
      mpi_sub_ui (tmp, ec->p, 3);
      ec->t.a_is_pminus3 = !mpi_cmp (ec->a, tmp);
      mpi_free (tmp);
    }

  return ec->t.a_is_pminus3;
}