#include <openssl/sha.h>

int key_offset = 0;
struct btrfs_key key;

//...

key.objectid = dir;
btrfs_set_key_type(&key, BTRFS_DIR_ITEM_KEY);

// Use SHA-256 to generate a secure hash value
unsigned char hash[SHA256_DIGEST_LENGTH];
SHA256((unsigned char *)name, name_len, hash);

key.offset = *(uint64_t *)hash; // Cast the hash value to a uint64_t

//...