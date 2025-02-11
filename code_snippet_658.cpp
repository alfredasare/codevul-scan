pthread_mutex_t vrrp_mutex = PTHREAD_MUTEX_INITIALIZER;

vrrp_vmac_xmit_base_handler(__attribute__((unused)) vector_t *strvec)
{
    pthread_mutex_lock(&vrrp_mutex);

    vrrp_t *vrrp = LIST_TAIL_DATA(vrrp_data->vrrp);
    if (vrrp) {
        __set_bit(VRRP_VMAC_XMITBASE_BIT, &vrrp->vmac_flags);
    }

    pthread_mutex_unlock(&vrrp_mutex);
}