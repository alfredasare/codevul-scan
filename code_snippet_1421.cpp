unsigned int end = bvec->bv_offset + bvec->bv_len - 1;
if (end >= PAGE_SIZE) {
/* Handle error condition */
return;
}
ASSERT(end < PAGE_SIZE);

... (rest of the function remains unchanged)