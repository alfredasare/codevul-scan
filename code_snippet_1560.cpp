static json_t *oidc_get_state_from_cookie(request_rec *r, oidc_cfg *c,
    const char *cookieValue) {
    json_t *result = NULL;
    char *decodedCookieValue = NULL;

    if (oidc_util_verify_cookie_value(r, c->crypto_passphrase, cookieValue, &decodedCookieValue)) {
        result = oidc_util_jwt_verify(r, c->crypto_passphrase, decodedCookieValue, &result);
    } else {
        error_log("Invalid or tampered cookie value");
        return NULL;
    }

    return result;
}