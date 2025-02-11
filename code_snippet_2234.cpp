ASN1_OBJECT *OBJ_nid2obj(int n)
{
ADDED\_OBJ ad,\*adp;
ASN1\_OBJECT ob;

if ((n >= 0) && (n < NUM\_NID) && (n != NID\_undef) && (nid\_objs[n].nid != NID\_undef))
return(&(nid\_objs[n]));
else if (added == NULL)
return(NULL);
else
{
ad.type=ADDED\_NID;
ad.obj= &ob;
ob.nid=n;
adp=lh\_ADDED\_OBJ\_retrieve(added,&ad);
if (adp != NULL)
return(adp->obj);
else
{
OBJerr(OBJ\_F\_OBJ\_NID2OBJ,OBJ\_R\_UNKNOWN\_NID);
return(NULL);
}
}
}