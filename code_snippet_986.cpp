#define MAX_ISIS_LSP_HEADER_SIZE sizeof(struct isis_lsp_header)

void isis_clear_checksum_lifetime(void *header)
{
    if (header && MAX_ISIS_LSP_HEADER_SIZE >= sizeof(struct isis_lsp_header)) {
        struct isis_lsp_header *header_lsp = (struct isis_lsp_header *)header;
        memset(header_lsp->checksum, 0, sizeof(header_lsp->checksum));
        memset(header_lsp->remaining_lifetime, 0, sizeof(header_lsp->remaining_lifetime));
    }
}