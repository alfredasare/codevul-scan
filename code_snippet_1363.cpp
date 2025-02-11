Struct condition *compiler\_create\_condition(struct filter\_op \*fop) {
struct condition \*cnd;

SAFE\_CALLOC(cnd, 1, sizeof(struct condition));

/* copy the instruction with proper bounds checking */
if (sizeof(struct filter\_op) < sizeof(struct condition)) {
 memcpy(&cnd->fop, fop, sizeof(struct filter\_op));
} else {
/* Handle error or set a maximum limit for the copy operation */
/* Log an error, for example: */
LOG\_ERROR("Error: filter\_op size exceeds condition size.");
free(cnd);
return NULL;
}

return cnd;
}