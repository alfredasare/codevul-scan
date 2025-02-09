static void btm_sec_check_upgrade(tBTM_SEC_DEV_REC  *p_dev_rec, BOOLEAN is_originator)
{
    tBTM_SP_UPGRADE     evt_data;

    BTM_TRACE_DEBUG ("btm_sec_check_upgrade...");

 /* Only check if link key already exists */
 if (!(p_dev_rec->sec_flags & BTM_SEC_LINK_KEY_KNOWN))
 return;
 if (btm_sec_is_upgrade_possible (p_dev_rec, is_originator) == TRUE)
 {
        BTM_TRACE_DEBUG ("need upgrade!! sec_flags:0x%x", p_dev_rec->sec_flags);
 /* upgrade is possible: check if the application wants the upgrade.
         * If the application is configured to use a global MITM flag,
         * it probably would not want to upgrade the link key based on the security level database */
        memcpy (evt_data.bd_addr, p_dev_rec->bd_addr, BD_ADDR_LEN);
        evt_data.upgrade = TRUE;
 if (btm_cb.api.p_sp_callback)
 (*btm_cb.api.p_sp_callback) (BTM_SP_UPGRADE_EVT, (tBTM_SP_EVT_DATA *)&evt_data);

        BTM_TRACE_DEBUG ("evt_data.upgrade:0x%x", evt_data.upgrade);
 if (evt_data.upgrade)
 {
 /* if the application confirms the upgrade, set the upgrade bit */
            p_dev_rec->sm4 |= BTM_SM4_UPGRADE;

 /* Clear the link key known to go through authentication/pairing again */
            p_dev_rec->sec_flags &= ~(BTM_SEC_LINK_KEY_KNOWN | BTM_SEC_LINK_KEY_AUTHED);
            p_dev_rec->sec_flags &= ~BTM_SEC_AUTHENTICATED;
            BTM_TRACE_DEBUG ("sec_flags:0x%x", p_dev_rec->sec_flags);
 }
 }
}
