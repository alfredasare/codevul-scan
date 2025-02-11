bson_iter_dbpointer (const bson_iter_t *iter,  /* IN */
                     uint32_t *collection_len, /* OUT */
                     const char **collection,  /* OUT */
                     const bson_oid_t **oid)   /* OUT */
{
   BSON_ASSERT (iter);

   if (collection) {
      *collection = NULL;
   }

   if (oid) {
      *oid = NULL;
   }

   if (ITER_TYPE (iter) == BSON_TYPE_DBPOINTER) {
      size_t len_offset = offsetof(bson_iter_t, d1);
      uint32_t *len_ptr = (uint32_t *)((char*)iter + len_offset);
      memcpy (collection_len, len_ptr, sizeof (*collection_len));
      *collection_len = BSON_UINT32_FROM_LE (*collection_len);

      if ((*collection_len) > 0) {
         (*collection_len)--;
      }

      size_t coll_offset = offsetof(bson_iter_t, d2);
      const char *coll_ptr = ((char*)iter + coll_offset);
      *collection = coll_ptr;

      size_t oid_offset = offsetof(bson_iter_t, d3);
      const bson_oid_t *oid_ptr = ((bson_oid_t *)((char*)iter + oid_offset));
      *oid = oid_ptr;
   }
}