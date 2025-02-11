static void print_pem_cert(FILE *out, certificate_t *cert)
{
    chunk_t encoded;

    if (cert->get_encoding(cert, CERT_PEM, &encoded))
    {
        char buffer[encoded.len + 1]; // Add 1 for null-termination
        strncpy(buffer, encoded.ptr, encoded.len);
        buffer[encoded.len] = '\0';
        fprintf(out, "%s\n", buffer);
    }
}