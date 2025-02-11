CJSON_PUBLIC(cJSON *) cJSON_CreateBool(cJSON_bool b)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        if(b!= 0 && b!= 1)
        {
            return NULL;
        }
        item->type = b? cJSON_True : cJSON_False;
    }

    return item;
}