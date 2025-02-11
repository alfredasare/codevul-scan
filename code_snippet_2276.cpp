char \*extract\_html(char \*buffer, size\_t size\_buffer)
{
	char \*end = buffer + size\_buffer - 3; // Limit to one character before potential CRLF sequence
	char \*cur;

	for (cur = buffer; cur < end; cur++)
		if (*cur == '\r' && *(cur+1) == '\n'
		    && *(cur+2) == '\r' && *(cur+3) == '\n')
			return cur + 4;
	return NULL;
}