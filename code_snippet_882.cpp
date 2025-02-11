parse_traffic(char *buf, int len, char *port, uint64_t *traffic)
{
    //...

    if (obj->type == json_object) {
        int i = 0;
        for (i = 0; i < obj->u.object.length; i++) {
            char *name = obj->u.object.values[i].name;
            json_value *value = obj->u.object.values[i].value;
            if (value->type == json_integer) {
                size_t name_len = strlen(name);
                if (name_len > 8) {
                    LOGE("Port name too long");
                    return -1;
                }
                for (size_t j = 0; j < name_len; j++) {
                    if (!isalnum(name[j]) && name[j]!= '.') {
                        LOGE("Invalid character in port name");
                        return -1;
                    }
                }
                strncpy(port, name, 8);
                *traffic = value->u.integer;
            }
        }
    }

    //...
}