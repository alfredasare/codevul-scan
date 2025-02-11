_gcry_mpi_point_init (mpi_point_t p)
{
    int err;

    p->x = mpi_new (0);
    if (p->x == NULL) {
        err = gcry_error (GCRYV_ERROR_ALLOC);
        return err;
    }

    p->y = mpi_new (0);
    if (p->y == NULL) {
        err = gcry_error (GCRYV_ERROR_ALLOC);
        return err;
    }

    p->z = mpi_new (0);
    if (p->z == NULL) {
        err = gcry_error (GCRYV_ERROR_ALLOC);
        return err;
    }
}