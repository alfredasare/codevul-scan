server_set_defaults (server *serv)
{
	if (serv->chantypes)
		free (serv->chantypes);
	if (serv->chanmodes)
		free (serv->chanmodes);
	if (serv->nick_prefixes)
		free (serv->nick_prefixes);
	if (serv->nick_modes)
		free (serv->nick_modes);

	serv->chantypes = strdup ("#&!+");
	if (!serv->chantypes) goto error;

	serv->chanmodes = strdup ("beI,k,l");
	if (!serv->chanmodes) goto error;

	serv->nick_prefixes = strdup ("@%+");
	if (!serv->nick_prefixes) goto error;

	serv->nick_modes = strdup ("ohv");
	if (!serv->nick_modes) goto error;

	serv->nickcount = 1;
	serv->end_of_motd = FALSE;
	serv->is_away = FALSE;
	serv->supports_watch = FALSE;
	serv->supports_monitor = FALSE;
	serv->bad_prefix = FALSE;
	serv->use_who = TRUE;
	serv->have_namesx = FALSE;
	serv->have_awaynotify = FALSE;
	serv->have_uhnames = FALSE;
	serv->have_whox = FALSE;
	serv->have_idmsg = FALSE;
	serv->have_accnotify = FALSE;
	serv->have_extjoin = FALSE;
	serv->have_server_time = FALSE;
	serv->have_sasl = FALSE;
	serv->have_except = FALSE;
	serv->have_invite = FALSE;

	return;

error:
	// Handle error and clean up resources
	free(serv->chantypes);
	free(serv->chanmodes);
	free(serv->nick_prefixes);
	free(serv->nick_modes);
	// ... and any other allocated resources

	// Terminate the function execution
	exit(EXIT_FAILURE);
}