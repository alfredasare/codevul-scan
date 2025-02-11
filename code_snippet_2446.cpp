static int oidc_authorization_response_error(request_rec *r, oidc_cfg *c,
		oidc_proto_state_t *proto_state, const char *error,
		const char *error_description) {
	const char *prompt = oidc_proto_state_get_prompt(proto_