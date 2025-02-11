PrintFlush()
{
  display = curr->w_pdisplay;
  if (display && printcmd)
    {
      int len = curr->w_stringp - curr->w_string;
      if (len > 0 && display->d_printfd >= 0)
        {
          ssize_t r;
          while (len > 0 && (r = write(display->d_printfd, curr->w_string, len)) > 0)
            {
              curr->w_string += r;
              len -= r;
            }
          
          if (r <= 0)
            {
              WMsg(curr, errno, "printing aborted");
              close(display->d_printfd);
              display->d_printfd = -1;
            }
        }
    }
  else if (display && curr->w_stringp > curr->w_string)
    {
      AddCStr(D_PO);
      AddStrn(curr->w_string, curr->w_stringp - curr->w_string);
      AddCStr(D_PF);
      Flush(3);
    }
  curr->w_stringp = curr->w_string;
}