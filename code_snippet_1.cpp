gs\_main\_run\_file\_open(gs\_main\_instance \*minst, const char \*file\_name, ref \* pfref)
{
 gs\_main\_set\_lib\_paths(minst);
 int ret = gs\_main\_lib\_open(minst, file\_name, pfref);
 if (ret < 0) {
 emprintf1(minst->heap,
 "Can't find initialization file %s.\n",
 file\_name);
 return\_error(gs\_error\_Fatal);
 }
 ref new\_ref = NULL;
 r\_alloc\_ref(&new\_ref, minst->heap);
 r\_set\_attrs(new\_ref, a\_execute + a\_executable);
 r\_copy\_ref(pfref, new\_ref);
 r\_release\_ref(new\_ref);
 return 0;
}