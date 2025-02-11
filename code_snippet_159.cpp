memcpy(info64->lo_crypt_name, info->lo_name, min(sizeof(info64->lo_crypt_name), LO_NAME_SIZE));
} else {
memcpy(info64->lo_file_name, info->lo_name, min(sizeof(info64->lo_file_name), LO_NAME_SIZE));
}
memcpy(info64->lo_encrypt_key, info->lo_encrypt_key, LO_KEY_SIZE);
}

#include <stddef.h>
#include <string.h>

size_t min(size_t a, size_t b) {
return a < b ? a : b;
}

struct loop_info {
// existing code
char lo_name[LO_NAME_SIZE];
char lo_encrypt_key[LO_KEY_SIZE];
};

struct loop_info64 {
// existing code
char lo_crypt_name[LO_NAME_SIZE];
char lo_file_name[LO_NAME_SIZE];
char lo_encrypt_key[LO_KEY_SIZE];
};