static int tcm_loop_get_endpoint_wwn(struct se_portal_group *se_tpg, char *wwn_buffer, int wwn_buffer_size)
{
	struct tcm_loop_tpg *tl_tpg =
		(struct tcm_loop_tpg *)se_tpg->se_tpg_fabric_ptr;
	int wwn_length = sizeof(tl_tpg->tl_hba->tl_wwn_address);

	if (wwn_buffer_size >= wwn_length) {
		memcpy(wwn_buffer, &tl_tpg->tl_hba->tl_wwn_address[0], wwn_length);
		return wwn_length;
	}

	return -EINVAL;
}