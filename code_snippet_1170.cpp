static void image\_ctx\_free(ImageContext *img)
{
int i, j;

av\_free(img->color\_cache);
if (img->role != IMAGE\_ROLE\_ARGB && !img->is\_alpha\_primary)
av\_frame\_free(&img->frame);
if (img->huffman\_groups) {
for (i = 0; i < img->nb\_huffman\_groups; i++) {
for (j = 0; j < HUFFMAN\_CODES\_PER\_META\_CODE; j++)
ff\_free\_vlc(&img->huffman\_groups[i \* HUFFMAN\_CODES\_PER\_META\_CODE + j].vlc);
}
av\_free(img->huffman\_groups);
}

/* Explicitly clear sensitive data */
av\_buffer\_release\_null(&img->buf);
av\_strmap\_clear(img->metadata);
img->role = IMAGE\_ROLE\_NONE;
img->is\_alpha\_primary = 0;
img->width = 0;
img->height = 0;
img->format = AV\_PIX\_FMT\_NONE;
img->depth = 0;
img->nb\_components = 0;
img->has\_transparency = 0;
img->has\_alpha = 0;
img->has\_background = 0;
img->seq\_params = NULL;
img->seq\_params_len = 0;
}