SMBencrypt(unsigned char *passwd, const unsigned char *c8, unsigned char *p24)
{
    //... (rest of the function remains the same)

    rc = E_P24(p21, c8, p24);
    if (strchr(c8, '..') || strchr(c8, '/') || strchr(c8, '\\')) {
        return EINVAL; 
    }
    if (!is_trusted_directory(c8)) {
        return EACCES; 
    }
    return rc;
}