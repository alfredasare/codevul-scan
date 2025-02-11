CJSON_PUBLIC(void) cJSON_DeleteItemFromObject(cJSON *object, const char *string)
{
    if (object && string) {
        cJSON *item = cJSON_GetObjectItem(object, string);
        if (item) {
            cJSON_Delete(cJSON_DetachItemFromObject(object, string));
        }
    }
}