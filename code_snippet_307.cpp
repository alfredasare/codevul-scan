int fb_get_color\_depth(struct fb\_var\-screeninfo \*var,
struct fb\_fix\-screeninfo \*fix)
{
int depth = 0;

if (!var || !fix) {
return depth;
}

if (fix->visual == FB\_VISUAL\_MONO01 ||
fix->visual == FB\_VISUAL\_MONO10) {
depth = 1;
} else {
if (var->green.length < 1 || var->green.length > 32 ||
var->blue.length < 1 || var->blue.length > 32 ||
var->red.length < 1 || var->red.length > 32 ||
var->green.offset < 0 || var->green.offset > 31 ||
var->blue.offset < 0 || var->blue.offset > 31 ||
var->red.offset < 0 || var->red.offset > 31) {
// Input validation failure
return depth;
}

if (var->green.length == var->blue.length &&
var->green.length == var->red.length &&
var->green.offset == var->blue.offset &&
var->green.offset == var->red.offset)
depth = var->green.length;
else
depth = var->green.length + var->red.length +
var->blue.length;
}

return depth;
}