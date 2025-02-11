path_out(PG_FUNCTION_ARGS)
{
	PATH	   *path = PG_GETARG_PATH_P(0);

	// Validate the path argument
	if (!path || path->npts <= 0 || path->p == NULL) {
		PG_RETURN_NULL();
	}

	// Whitelist validation for path structure and components
	if ((path->closed && path->npts > 1) || (path->open && path->npts <= 0)) {
		PG_RETURN_NULL();
	}

	PG_RETURN_CSTRING(path_encode(path->closed? PATH_CLOSED : PATH_OPEN, path->npts, path->p));
}