static void print\_pem\_cert(FILE \*out, certificate\_t \*cert)
{
	chunk\_t encoded;

	if (cert->get\_encoding(cert, CERT\_PEM, &encoded))
	{
		if (encoded.len > 0 && encoded.ptr != NULL)
		{
			fprintf(out, "%s", encoded.ptr);
			free(encoded.ptr);
		}
	}
}