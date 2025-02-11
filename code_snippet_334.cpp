compile\_length\_string\_raw\_node(StrNode* sn, regex\_t* reg)
{
if (sn == NULL)
return 0;

if (sn->end <= sn->s)
return 0;

return add\_compile\_string\_length(sn->s, 1 /* sb */, (int )(sn->end - sn->s),
reg, 0);
}