gs\_heap\_object\_type(const gs\_memory\_t \* mem, const void \*ptr)
{
const gs\_malloc\_block\_t *block = (const gs\_malloc\_block\_t *)((char *)ptr - sizeof(gs\_malloc\_block\_t));
return block->type;
}