nvmet_fc_tgt_a_get(struct nvmet_fc_tgt_assoc *assoc)
{
	if (!assoc) {
		return 0;
	}

	return kref_get_unless_zero(&assoc->ref);
}