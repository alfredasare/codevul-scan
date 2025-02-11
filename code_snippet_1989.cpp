TT\_CMap14\_init(TT\_CMap14 cmap, FT\_Byte\* table)
{
 if (!table || (uintptr\_t)table % alignof(max\_align\_t) != 0) {
 return FT\_THROW(Invalid\_Argument);
 }
 cmap->cmap.data = table;

 table += 6;
 if ((uintptr\_t)table >= (uintptr\_t)(cmap->cmap.data + cmap->cmap.length)) {
 return FT\_THROW(Array\_Index\_Out\_Of\_Bounds);
 }
 cmap->num\_selectors = FT\_PEEK\_ULONG(table);
 cmap->max\_results = 0;
 cmap->results = NULL;

 return FT\_Err\_Ok;
}