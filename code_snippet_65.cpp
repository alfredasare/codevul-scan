CWE_189_FIXED_EVAL_NUMBER(uschar **sptr, BOOL decimal, uschar **error)
{
register int c;
int_eximarith_t n;
uschar *s = *sptr;

while (isspace(*s)) s++;
c = *s;

if (isdigit(c))
  {
  int count;
  (void)sscanf(CS s, (decimal? SC_EXIM_DEC "%n" : SC_EXIM_ARITH "%n"), &n, &count);
  s += count;

  // Parse optional suffix
  long suffix_multiplier = 1;
  if (s[0] == 'k')
    {
    suffix_multiplier = 1024;
    s++;
    }
  else if (s[0] == 'm')
    {
    suffix_multiplier = 1024*1024;
    s++;
    }
  else if (s[0] == 'g')
    {
    suffix_multiplier = 1024*1024*1024;
    s++;
    }

  n *= suffix_multiplier;

  while (isspace (*s)) s++;
  }
else
  {
  *error = US"expecting number or opening parenthesis";
  n = 0;
  }

*sptr = s;
return n;
}