static char *tcm_loop_get_endpoint_wwn(struct se_portal_group *se_tpg)
{
    struct tcm_loop_tpg *tl_tpg = (struct tcm_loop_tpg *)se_tpg->se_tpg_fabric_ptr;
    char *wwn_address = tl_tpg->tl_hba->tl_wwn_address;

    // Validate and sanitize the wwn_address buffer
    wwn_address = str_replace_invalid_chars(wwn_address, '_');

    return wwn_address;
}

char *str_replace_invalid_chars(char *str, char replacement_char)
{
    char *new_str = malloc(strlen(str) + 1);
    int i = 0;
    for (char *c = str; *c; c++) {
        if (!isalnum(*c) && *c!= replacement_char) {
            *new_str++ = replacement_char;
        } else {
            *new_str++ = *c;
        }
    }
    *new_str = '\0';
    return new_str;
}