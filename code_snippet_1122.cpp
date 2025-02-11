static json_t *json_integer_copy(const json_t *integer)
{
    json_t *new_integer = json_integer(json_integer_value(integer));
    json_object_set_number(new_integer, NULL, json_integer_value(integer));
    return new_integer;
}