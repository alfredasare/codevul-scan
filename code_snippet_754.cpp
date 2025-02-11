static void qeth_fill_ipa_cmd_header(struct qeth_card *card,
				      struct qeth_ipa_cmd *cmd, __u8 command,
				      enum qeth_prot_versions prot)
{
    size_t cmd_size = sizeof(*cmd);
    memset(cmd, 0, cmd_size);
    //... rest of the function remains the same...
}