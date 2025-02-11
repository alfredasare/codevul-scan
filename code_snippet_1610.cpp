GF_Box *gf\_dvcC\_New()
{
	GF\_DOVIConfigurationBox *tmp = (GF\_DOVIConfigurationBox *)gf\_malloc(sizeof(GF\_DOVIConfigurationBox));
	if (tmp == NULL) return NULL;
	memset(tmp, 0, sizeof(GF\_DOVIConfigurationBox));
	tmp->type = GF\_ISOM\_BOX\_TYPE\_DVCC;
	tmp->max\_size = sizeof(GF\_DOVIConfigurationBox); // Limit the size
	return (GF\_Box *)tmp;
}