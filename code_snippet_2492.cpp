FT\_Renderer FT\_Lookup\_Renderer(FT\_Library library, FT\_Glyph\_Format format, FT\_ListNode\* node)
{
FT\_ListNode  cur = NULL;
FT\_Renderer  result = NULL;

if (library != NULL)
{
cur = library->renderers.head;

if (node != NULL)
{
if (\*node != NULL)
cur = (\*node)->next;
*node = NULL;
}

while (cur != NULL)
{
FT\_Renderer renderer = FT\_RENDERER(cur->data);

if (renderer != NULL && renderer->glyph\_format == format)
{
*node = cur;
result = renderer;
break;
}
cur = cur->next;
}
}

return result;
}