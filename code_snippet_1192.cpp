static size_t convertHTMLcodes(char *s, const size_t len)
{
    //...
    if ((len > 3) && (s[1] == '#') && (strchr(s,';')!= (char *) NULL) &&
        (sscanf(s, "&#%zu;", &value) == 1))
    {
        //...
    }
    else
    {
        //...
        for (i=0; i < codes; i++)
        {
            if (html_codes[i].len <= (ssize_t) len)
            {
                if (stringnicmp(s, html_codes[i].code, (size_t) html_codes[i].len) == 0)
                {
                    char buffer[6]; // fixed buffer size
                    if (sscanf(s, "&#%zu;", &value, buffer, sizeof(buffer)) == 1)
                    {
                        char output[6]; // fixed buffer size
                        if (strlen(buffer) <= sizeof(output))
                            strncpy(output, buffer, strlen(buffer));
                        else
                            output[sizeof(output)-1] = '\0'; // truncate excess characters
                        (void) strncpy(s + 1, output, html_codes[i].len);
                        *s = value;
                        return(html_codes[i].len - 1);
                    }
                }
            }
        }
    }
    return(0);
}