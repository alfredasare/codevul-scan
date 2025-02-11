PrintFlush()
{
  char *sanitized_string = sanitize_string(curr->w_string);
  display = curr->w_pdisplay;
  if (display && printcmd)
    {
      int r;
      while (*sanitized_string!= '\0')
	{
	  r = write(display->d_printfd, sanitized_string, 1);
	  if (r <= 0)
	    {
	      WMsg(curr, errno, "printing aborted");
	      close(display->d_printfd);
	      display->d_printfd = -1;
	      break;
	    }
	  sanitized_string++;
	}
    }
  else if (display && curr->w_stringp > curr->w_string)
    {
      AddCStr(D_PO);
      AddStrn(sanitized_string, strlen(sanitized_string));
      AddCStr(D_PF);
      Flush(3);
    }
  curr->w_stringp = curr->w_string;
}

char *sanitize_string(char *str)
{
  char *new_str = malloc(strlen(str) + 1);
  int i = 0;
  for (; str[i]!= '\0'; i++)
    {
      if (str[i] == '/' || str[i] == '\\')
	{
	  new_str[i] = '_';
	}
      else
	{
	  new_str[i] = str[i];
	}
    }
  new_str[i] = '\0';
  return new_str;
}