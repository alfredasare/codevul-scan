vbf_stp_retry(struct worker *wrk, struct busyobj *bo)
{
	struct vfp_ctx *vfc;

	CHECK_OBJ_NOTNULL(wrk, WORKER_MAGIC);
	if (bo == NULL || bo->magic != BUSYOBJ_MAGIC) {
		return F_STP_NULL;
	}
	vfc = bo->vfc;
	if (vfc == NULL || vfc->magic != VFP_CTX_MAGIC) {
		return F_STP_NULL;
	}

	assert(bo->fetch_objcore->boc->state <= BOS_REQ_DONE);

	VSLb_ts_busyobj(bo, "Retry", W_TIM_real(wrk));

	/* VDI_Finish must have been called before */
	if (bo->director_state != DIR_S_NULL) {
		return F_STP_DIR_STATE;
	}

	/* reset other bo attributes - See VBO_GetBusyObj */
	bo->storage = NULL;
	bo->storage_hint = NULL;
	bo->do_esi = 0;
	bo->do_stream = 1;

	/* reset fetch processors */
	VFP_Setup(vfc);

	VSL_ChgId(bo->vsl, "bereq", "retry", VXID_Get(wrk, VSL_BACKENDMARKER));
	VSLb_ts_busyobj(bo, "Start", bo->t_prev);
	http_VSL_log(bo->bereq);

	return (F_STP_STARTFETCH);
}