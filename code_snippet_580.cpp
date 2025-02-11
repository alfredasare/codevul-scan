#define MAX_INPUT_LENGTH 1024

if (argc < 2 || argv == NULL) {
    fprintf(stderr, "sm_broadcast_xml_config: Invalid arguments.\n");
    return -1;
}

arg_len = strlen(argv[1]);
if (arg_len >= MAX_INPUT_LENGTH) {
    fprintf(stderr, "sm_broadcast_xml_config: Input string is too long. Maximum length is %d characters.\n", MAX_INPUT_LENGTH);
    return -1;
}

if((res = fm_mgr_simple_query(hdl, FM_ACT_GET, FM_DT_SM_BROADCAST_XML_CONFIG, mgr, arg_len, argv[1], &ret_code)) != FM_CONF_OK)
{
    fprintf(stderr, "sm_broadcast_xml_config: Failed to retrieve data:\n"
           "\tError:(%d) %s \n\tRet code:(%d) %s\n",
           res, fm_mgr_get_error_str(res),ret_code,
           fm_mgr_get_resp_error_str(ret_code));
} else {
    printf("sm_broadcast_xml_config: Successfully sent XML broadcast config command to local mgr instance\n");
}

return 0;