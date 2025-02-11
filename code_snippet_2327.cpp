PHP\_FUNCTION(locale\_accept\_from\_http)
{
	UEnumeration \*available;
	char \*http\_accept = NULL;
	int http\_accept\_len;
	UErrorCode status = 0;
	int len;
	char resultLocale[INTL\_MAX\_LOCALE\_LEN+1];
	UAcceptResult outResult;

	if(zend\_parse\_parameters( ZEND\_NUM\_ARGS() TSRMLS\_CC, "s", &http\_accept, &http\_accept\_len) == FAILURE)
	{
		intl\_error\_set( NULL, U\_ILLEGAL\_ARGUMENT\_ERROR,
		"locale\_accept\_from\_http: unable to parse input parameters", 0 TSRMLS\_CC );
		RETURN\_FALSE;
	}
	available = ures\_openAvailableLocales(NULL, &status);
	INTL\_CHECK\_STATUS(status, "locale\_accept\_from\_http: failed to retrieve locale list");

	// Check if the length of http\_accept is not greater than the size of resultLocale
	if (http\_accept\_len > INTL\_MAX\_LOCALE\_LEN) {
		uenum\_close(available);
		INTL\_SET\_ERROR(status, "locale\_accept\_from\_http: http\_accept is too long", "");
		RETURN\_FALSE;
	}

	len = uloc\_acceptLanguageFromHTTP(resultLocale, INTL\_MAX\_LOCALE\_LEN, 
						&outResult, http\_accept, available, &status);
	uenum\_close(available);
	INTL\_CHECK\_STATUS(status, "locale\_accept\_from\_http: failed to find acceptable locale");
	if (len < 0 || outResult == ULOC\_ACCEPT\_FAILED) {
		RETURN\_FALSE;
	}
	RETURN\_STRINGL(resultLocale, len, 1);
}