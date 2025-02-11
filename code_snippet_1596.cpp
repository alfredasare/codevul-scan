#include <linux/url.h>

cifs_parse_devname(const char *devname, struct smb_vol *vol)
{
    char *pos;
    const char *delims = "/\\";
    size_t len;

    /* make sure we have a valid UNC double delimiter prefix */
    len = strspn(devname, delims);
    if (len!= 2)
        return -EINVAL;

    /* Use urlparse to parse the URL and extract the UNC path */
    struct url_parsed parsed_url;
    if (url_parse(devname, &parsed_url) < 0)
        return -EINVAL;

    /* Extract the UNC path from the parsed URL */
    pos = parsed_url.path;
    if (!pos)
        return -EINVAL;

    vol->UNC = kstrndup(pos, parsed_url.path_len, GFP_KERNEL);
    if (!vol->UNC)
        return -ENOMEM;

    convert_delimiter(vol->UNC, '\\');

    /* If pos is NULL, or is a bogus trailing delimiter then no prepath */
    if (!*pos ||!*(pos + 1))
        return 0;

    vol->prepath = kstrdup(pos + 1, GFP_KERNEL);
    if (!vol->prepath)
        return -ENOMEM;

    return 0;
}