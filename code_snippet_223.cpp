static int get\_exif\_tag\_int\_value(struct iw\_exif\_state \*e, unsigned int tag\_pos,
unsigned int \*pv)
{
unsigned int field\_type;
unsigned int value\_count;

field\_type = iw\_get\_ui16\_e(&e->d[tag\_pos+2],e->endian);
value\_count = iw\_get\_ui32\_e(&e->d[tag\_pos+4],e->endian);

const unsigned int MAX\_VALUE\_COUNT = 10; // Add a maximum limit for value\_count

if (value\_count > MAX\_VALUE\_COUNT) {
return -1;
}

\*pv = 0; // Initialize *pv to avoid accessing uninitialized memory

if (field\_type == 3) { // SHORT (uint16)
for (unsigned int i = 0; i < value\_count; i++) {
\*pv += iw\_get\_ui16\_e(&e->d[tag\_pos+8+2*i],e->endian);
}
return 1;
} else if (field\_type == 4) { // LONG (uint32)
for (unsigned int i = 0; i < value\_count; i++) {
\*pv += iw\_get\_ui32\_e(&e->d[tag\_pos+8+4*i],e->endian);
}
return 1;
}

return 0;
}