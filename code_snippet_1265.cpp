key_ref_t find_key_to_update(key_ref_t keyring_ref,
                             const struct keyring_index_key *index_key)
{
        if (!keyring_ref || keyring_ref->serial == 0) {
                klog("Invalid keyring reference");
                return NULL;
        }

        struct key *keyring = key_ref_to_ptr(keyring_ref);

        kenter("{%d},{%s,%s}",
               keyring->serial, index_key->type->name, index_key->description);

        const void *object = assoc_array_find(&keyring->keys, &keyring_assoc_array_ops,
                                  index_key);

        if (object) {
                struct key *key = keyring_ptr_to_key(object);
                if (!(key->flags & ((1 << KEY_FLAG_INVALIDATED) |
                                   (1 << KEY_FLAG_REVOKED)))) {
                        __key_get(key);
                        return make_key_ref(key, is_key_possessed(keyring_ref));
                }
        }

        kleave(" = NULL");
        return NULL;
}