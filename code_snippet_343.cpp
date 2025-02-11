static void tg3_probe_ncsi(struct tg3 *tp)
{
	u32 apedata;
	const u32 sig_limit = TG3_APE_SEG_SIG_MAGIC + 1;
	const u32 fw_status_limit = TG3_APE_FW_STATUS + sizeof(u32);
	const u32 fw_features_limit = TG3_APE_FW_FEATURES + sizeof(u32);

	apedata = tg3_ape_read32(tp, TG3_APE_SEG_SIG);
	if (apedata < TG3_APE_SEG_SIG || apedata >= sig_limit)
		return;

	apedata = tg3_ape_read32(tp, TG3_APE_FW_STATUS);
	if (apedata < TG3_APE_FW_STATUS || apedata >= fw_status_limit)
		return;

	apedata = tg3_ape_read32(tp, TG3_APE_FW_FEATURES);
	if (apedata < TG3_APE_FW_FEATURES || apedata >= fw_features_limit)
		return;

	if (apedata & TG3_APE_FW_FEATURE_NCSI)
		tg3_flag_set(tp, APE_HAS_NCSI);
}