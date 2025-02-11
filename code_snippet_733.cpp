#include <linux/io.h>
#include <linux/resource.h>

static void uvesafb_ioremap(struct fb_info *info)
{
    resource_size_t size = resource_size(&info->fix.smem_resource);
    void *base = iomem_resource(info->fix.smem_start, size);
    info->screen_base = base;
}