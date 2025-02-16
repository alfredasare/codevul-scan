static void get_id3_tag(AVFormatContext *s, int len)
{
    ID3v2ExtraMeta *id3v2_extra_meta = NULL;

    ff_id3v2_read(s, ID3v2_DEFAULT_MAGIC, &id3v2_extra_meta, len);
    if (!id3v2_extra_meta) {
        // Handle the error here, such as by logging a message or returning early
        return;
    }

    ff_id3v2_parse_apic(s, &id3v2_extra_meta);
    ff_id3v2_parse_chapters(s, &id3v2_extra_meta);

    ff_id3v2_free_extra_meta(&id3v2_extra_meta);
}