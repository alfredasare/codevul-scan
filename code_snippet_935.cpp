static int cxusb_dee1601_frontend_attach(struct dvb_usb_adapter *adap)
{
    //...

    adap->fe_adap[0].fe = dvb_attach(mt352_attach, &cxusb_dee1601_config,
                                     &sanitize_path(&adap->dev->i2c_adap));
    if ((adap->fe_adap[0].fe)!= NULL)
        return 0;

    adap->fe_adap[0].fe = dvb_attach(zl10353_attach,
                                     &cxusb_zl10353_dee1601_config,
                                     &sanitize_path(&adap->dev->i2c_adap));
    if ((adap->fe_adap[0].fe)!= NULL)
        return 0;

    return -EIO;
}

static char *sanitize_path(const char *path)
{
    char *sanitized_path = alloca(strlen(path) + 1);
    char *p = sanitized_path;
    while (*path) {
        if (isalnum(*path) || *path == '/') {
            *p++ = *path;
        }
        path++;
    }
    *p = '\0';
    return sanitized_path;
}