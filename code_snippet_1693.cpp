int inflate()
{
 int e;                /* last block flag */
 int r;                /* result code */
 unsigned h;           /* maximum struct huft's malloc'ed */

 /* initialize window, bit buffer */
 wp = 0;
 bk = 0;
 bb = 0;

 /* decompress until the last block */
 h = 0;
 do {
 hufts = 0;
 if ((r = inflate\_block(&e)) != 0)
 return r;
 if (hufts > h)
 h = hufts;
 } while (!e);

 /* Undo too much lookahead. The next read will be byte aligned so we
 * can discard unused bits in the last meaningful byte.
 */
 while (bk >= 8) {
 bk -= 8;
 inptr--;
 }

 /* trim output buffer to its actual size before returning it */
 trim\_output\_buffer(wp);

 /* flush out slide */
 flush\_output(wp);

 /* return success */
 Trace ((stderr, "<%u> ", h));
 return 0;
}

void trim\_output\_buffer(unsigned char \*start, unsigned char \*end) {
 size\_t len = end - start;
 memmove(start, start, len);
}