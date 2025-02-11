`#define MAX_PATH 260`

TT\_String\* tt\_name\_ascii\_from\_utf16(TT\_Name entry, FT\_Memory memory)
{
FT\_String\* string = NULL;
FT\_UInt len, code, n;
FT\_Byte\* read = (FT\_Byte&lt;span class="kt"&gt;<span class="kr">\*</span>&lt;/span&gt;)entry−&gt;string;
FT\_Error error;

len = (FT\_UInt)entry−&gt;stringLength / 2;

// Limit the maximum length of the ASCII string
if (len > MAX\_PATH)
{
len = MAX\_PATH;
}

if (FT\_NEW\_ARRAY(string, len + 1))
{
return NULL;
}

for (n = 0; n < len; n++)
{
code = FT\_NEXT\_USHORT(read);

if (code == 0)
{
break;
}

// Check if the destination buffer is large enough
if (n >= MAX\_PATH)
{
break;
}

if (code < 32 || code > 127)
{
code = ’?’;
}

string[n] = (char)code;
}

string[n] = 0;

return string;
}

Please note that I have corrected the data type of the `string` variable from `FT_String` to `FT_String*` to ensure proper memory allocation. Additionally, I introduced a bound check before updating the ASCII string to prevent buffer overflows.