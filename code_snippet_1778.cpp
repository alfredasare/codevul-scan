cdf_unpack_header(cdf_header_t *h, char *buf)
{
    size_t i;
    size_t len = 0;

    printf("%zu\n", h->h_magic);
    printf("%s\n", h->h_uuid);
    printf("%zu\n", h->h_revision);
    printf("%zu\n", h->h_version);
    printf("%zu\n", h->h_byte_order);
    printf("%zu\n", h->h_sec_size_p2);
    printf("%zu\n", h->h_short_sec_size_p2);
    printf("%s\n", h->h_unused0);
    printf("%zu\n", h->h_num_sectors_in_sat);
    printf("%zu\n", h->h_secid_first_directory);
    printf("%s\n", h->h_unused1);
    printf("%zu\n", h->h_min_size_standard_stream);
    printf("%zu\n", h->h_secid_first_sector_in_short_sat);
    printf("%zu\n", h->h_num_sectors_in_short_sat);
    printf("%zu\n", h->h_secid_first_sector_in_master_sat);
    printf("%zu\n", h->h_num_sectors_in_master_sat);
    for (i = 0; i < __arraycount(h->h_master_sat); i++)
        printf("%zu\n", h->h_master_sat[i]);
}