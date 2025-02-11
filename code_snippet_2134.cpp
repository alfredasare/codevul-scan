int oz_cdev_init(void)
{
    int appId = OZ_APPID_SERIAL; // hardcoded value
    if (appId < 0 || appId > MAX_APP_ID) {
        return -1;
    }
    oz_app_enable(appId, 1);
    return 0;
}