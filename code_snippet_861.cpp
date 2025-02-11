void isis_clear_checksum_lifetime(void *header)
{
    struct isis_lsp_header *header_lsp = (struct isis_lsp_header *) header;

    if (header_lsp == NULL || header_lsp->checksum == NULL || header_lsp->remaining_lifetime == NULL) {
        return;
    }

    if (header_lsp->checksum[0] >= sizeof(header_lsp->checksum) || header_lsp->checksum[1] >= sizeof(header_lsp->checksum)) {
        return;
    }

    if (header_lsp->remaining_lifetime[0] >= sizeof(header_lsp->remaining_lifetime) || header_lsp->remaining_lifetime[1] >= sizeof(header_lsp->remaining_lifetime)) {
        return;
    }

    header_lsp->checksum[0] = 0;
    header_lsp->checksum[1] = 0;
    header_lsp->remaining_lifetime[0] = 0;
    header_lsp->remaining_lifetime[1] = 0;
}