static int ftrace_function_check_pred(struct filter_pred *pred)
{
	struct ftrace_event_field *field = pred->field;
	size_t name_len;

	if ((pred->op != OP_EQ) && (pred->op != OP_NE))
		return -EINVAL;

	name_len = strnlen(field->name, MAX_FIELD_NAME_LEN);
	if (name_len >= MAX_FIELD_NAME_LEN || name_len == 0 ||
	    strpbrk(field->name, "\\\"'"))
		return -EINVAL;

	if (strcmp(field->name, "ip"))
		return -EINVAL;

	return 0;
}