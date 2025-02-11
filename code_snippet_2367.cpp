#define OZ_APP_ENABLED 1

int oz_cdev_init(void)
{
	oz_app_enable(OZ_APPID_SERIAL, OZ_APP_ENABLED);
	return 0;
}