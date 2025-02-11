CJSON_PUBLIC(void) cJSON_DeleteItemFromObject(cJSON *object, const char *string)
{
    if (object == NULL || string == NULL) {
        return;
    }

    cJSON_Delete(cJSON_DetachItemFromObject(object, string));
}