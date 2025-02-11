#include <string.h>

vrrp_vmac_xmit_base_handler(__attribute__((unused)) vector_t *strvec)
{
    vrrp_t *vrrp = LIST_TAIL_DATA(vrrp_data->vrrp);

    if (strvec && strlen(strvec) > MAX_SAFE_LENGTH) {
        return; // Reject the input if it exceeds the maximum safe length
    }

    __set_bit(VRRP_VMAC_XMITBASE_BIT, &vrrp->vmac_flags);
}