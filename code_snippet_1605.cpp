int xmlrpc_getlast_error(void)
{
	int error\_code = xmlrpc\_error\_code;
	xmlrpc\_error\_code = 0; // Reset the global variable to a safe value
	return error\_code;
}