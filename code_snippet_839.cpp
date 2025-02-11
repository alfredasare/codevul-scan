event_change_size( RenderState  state,
                   double       delta )
{
  double  char_size = state->char_size;

  const double min_char_size = 6.0;
  const double max_char_size = 300.0;

  char_size = fmin(fmax(char_size + delta, min_char_size), max_char_size);

  render_state_set_size( state, char_size );
}