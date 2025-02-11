static char *iscsi_check_valuelist_for_support(
	struct iscsi_param *param,
	char *value)
{
	char *tmp1 = NULL, *tmp2 = NULL;
	char *acceptor_values = NULL, *proposer_values = NULL;

	value = sanitize_input(value);
	param->value = sanitize_input(param->value);

	acceptor_values = param->value;
	proposer_values = value;

	do {
		if (!proposer_values)
			return NULL;
		tmp1 = strchr(proposer_values, ',');
		if (tmp1)
			*tmp1 = '\0';
		acceptor_values = param->value;
		do {
			if (!acceptor_values) {
				if (tmp1)
					*tmp1 = ',';
				return NULL;
			}
			tmp2 = strchr(acceptor_values, ',');
			if (tmp2)
				*tmp2 = '\0';
			if (!strcmp(acceptor_values, proposer_values)) {
				if (tmp2)
					*tmp2 = ',';
				goto out;
			}
			if (tmp2)
				*tmp2++ = ',';

			acceptor_values = tmp2;
		} while (acceptor_values);
		if (tmp1)
			*tmp1++ = ',';
		proposer_values = tmp1;
	} while (proposer_values);

out:
	return proposer_values;
}

char *sanitize_input(char *input)
{
	static const char valid_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-,.";
	char *p = input;
	char *q = input;

	while (*p) {
		if (strchr(valid_chars, *p) == NULL) {
			*p = '_'; // or some other safe replacement character
		}
		p++;
	}

	return input;
}