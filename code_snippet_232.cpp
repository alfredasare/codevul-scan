static trans\_t\* AllocTrans(char \*original, char \*translated[MAX\_LANGUAGES]) {
 trans\_t \*t;
 int i;

 t = malloc(sizeof(trans\_t));
 memset(t, 0, sizeof(trans\_t));

 if (original) {
 strncpy(t->original, original, MAX\_TRANS\_STRING - 1);
 t->original[MAX\_TRANS\_STRING - 1] = '\0';
 }

 if (translated) {
 for (i = 0; i < MAX\_LANGUAGES; i++) {
 if (translated[i]) {
 strncpy(t->translated[i], translated[i], MAX\_TRANS\_STRING - 1);
 t->translated[i][MAX\_TRANS\_STRING - 1] = '\0';
 }
 }
 }

 return t;
}