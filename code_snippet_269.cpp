static char * exif_get_tagname(int tag_num, char *ret, int len, tag_table_type tag_table TSRMLS_DC)
{
    int i, t;
    char tmp[32];

    for (i = 0; (t = tag_table[i].Tag)!= TAG_END_OF_LIST; i++) {
        if (t == tag_num) {
            if (ret && len > 0) { 
                strlcpy(ret, tag_table[i].Desc, len); 
                return ret;
            }
            return tag_table[i].Desc;
        }
    }

    if (ret && len > 0) {
        snprintf(tmp, sizeof(tmp), "UndefinedTag:0x%04X", tag_num);
        strcpy(ret, tmp); 
        return ret;
    }
    return "";
}