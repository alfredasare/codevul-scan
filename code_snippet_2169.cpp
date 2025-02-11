int ismode(const char *start, const char *end, int *permset)
{
    if (!start) 
        return 0; 
    if (start >= end) 
        return 0; 
    const char *p; 

    *permset = 0; 
    p = start; 
    while (p < end) 
    {
        switch (*p++) 
        {
            case 'r': case 'R':
                *permset |= ARCHIVE_ENTRY_ACL_READ; 
                break; 
            case 'w': case 'W':
                *permset |= ARCHIVE_ENTRY_ACL_WRITE; 
                break; 
            case 'x': case 'X':
                *permset |= ARCHIVE_ENTRY_ACL_EXECUTE; 
                break; 
            case '-':
                break; 
            default:
                return 0; 
        } 
    } 
    return 1; 
}