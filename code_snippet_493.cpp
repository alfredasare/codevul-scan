int sm_broadcast_xml_config(p_fm_config_conx_hdlt hdl, fm_mgr_type_t mgr, int argc, char *argv[]) {
    fm_mgr_config_errno_t res;
    fm_msg_ret_code_t ret_code;
    char error_message[256]; // Define a limited buffer size

    if ((res = fm_mgr_simple_query(hdl, FM_ACT_GET, FM_DT_SM_BROADCAST_XML_CONFIG, mgr, 0, NULL, &ret_code))!= FM_CONF_OK) {
        snprintf(error_message, sizeof(error_message),
                 "sm_broadcast_xml_config: Failed to retrieve data:\n\tError: (%d) %s \n\tRet code: (%d) %s\n",
                 res, fm_mgr_get_error_str(res), ret_code, fm_mgr_get_resp_error_str(ret_code));
        fprintf(stderr, "%s", error_message);
    } else {
        printf("sm_broadcast_xml_config: Successfully sent XML broadcast config command to local mgr instance\n");
    }
    return 0;
}