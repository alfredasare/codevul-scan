json_t *json_false(void)
{
    json_t false_value = {JSON_FALSE, (size_t)-1};
    return json_copy(&false_value);
}