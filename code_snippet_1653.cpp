#include <stdbool.h>
#include <assert.h>

UNCURL_EXPORT int32_t uncurl_ws_close(struct uncurl_conn *ucc, uint16_t status_code)
{
    if (status_code < 100 || status_code > 599) {
        return UNCURL_E_INVALID_STATUS_CODE;
    }

    uint16_t status_code_be = htons(status_code);

    return uncurl_ws_write(ucc, (char *) &status_code_be, sizeof(uint16_t), UNCURL_WSOP_CLOSE);
}