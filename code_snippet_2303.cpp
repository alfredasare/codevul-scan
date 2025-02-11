_gcry\_mpi\_point\_init (mpi\_point\_t p)
{
p->x = mpi\_new (0);
if (p->x == NULL) {
return -1;
}

p->y = mpi\_new (0);
if (p->y == NULL) {
mpi\_free (p->x);
return -1;
}

p->z = mpi\_new (0);
if (p->z == NULL) {
mpi\_free (p->y);
mpi\_free (p->x);
return -1;
}
}