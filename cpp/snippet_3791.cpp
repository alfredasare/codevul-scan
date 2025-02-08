_handle_cursor_control(Termpty *ty, const Eina_Unicode *cc)
{
   switch (*cc)
     {
      case 0x07: // BEL '\a' (bell)
         ty->termstate.had_cr = 0;
         if (ty->cb.bell.func) ty->cb.bell.func(ty->cb.bell.data);
         return;
      case 0x08: // BS  '\b' (backspace)
         DBG("->BS");
         ty->termstate.had_cr = 0;
         ty->termstate.wrapnext = 0;
         ty->cursor_state.cx--;
         TERMPTY_RESTRICT_FIELD(ty->cursor_state.cx, 0, ty->w);
         return;
      case 0x09: // HT  '\t' (horizontal tab)
         DBG("->HT");
         ty->termstate.had_cr = 0;
         TERMPTY_SCREEN(ty, ty->cursor_state.cx, ty->cursor_state.cy).att.tab = 1;
         ty->termstate.wrapnext = 0;
         ty->cursor_state.cx += 8;
         ty->cursor_state.cx = (ty->cursor_state.cx / 8) * 8;
         TERMPTY_RESTRICT_FIELD(ty->cursor_state.cx, 0, ty->w);
         return;
      case 0x0a: // LF  '\n' (new line)
      case 0x0b: // VT  '\v' (vertical tab)
      case 0x0c: // FF  '\f' (form feed)
         DBG("->LF");
         if (ty->termstate.had_cr)
           {
              TERMPTY_SCREEN(ty, ty->termstate.had_cr_x,
                                 ty->termstate.had_cr_y).att.newline = 1;
           }
         ty->termstate.had_cr = 0;
         ty->termstate.wrapnext = 0;
         if (ty->termstate.crlf) ty->cursor_state.cx = 0;
         ty->cursor_state.cy++;
         termpty_text_scroll_test(ty, EINA_TRUE);
         return;
      case 0x0d: // CR  '\r' (carriage ret)
         DBG("->CR");
         if (ty->cursor_state.cx != 0)
           {
              ty->termstate.had_cr_x = ty->cursor_state.cx;
              ty->termstate.had_cr_y = ty->cursor_state.cy;
              ty->termstate.wrapnext = 0;
           }
         ty->cursor_state.cx = 0;
         return;
      default:
         return;
     }
}
