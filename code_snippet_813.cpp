Here's the fixed version of the code with the recommended changes applied:


static int appendDynamic(dynamicPtr * dp, const void *src, int size)
{
	int bytesNeeded;
	char *tmp;

	if(!dp->dataGood) {
		return FALSE;
	}

	bytesNeeded = dp->pos + size;

	if(bytesNeeded > dp->realSize) {
		if(!dp->freeOK) {
			return FALSE;