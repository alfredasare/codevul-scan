gray_start_cell( RAS_ARG_ uint32_t  ex,
                 uint32_t  ey )
{
  if ( ex > ras.max_ex )
    ex = ras.max_ex;

  if ( ex < ras.min_ex )
    ex = ras.min_ex - 1;

  ras.area    = 0;
  ras.cover   = 0;
  ras.ex      = (uint32_t)(ex - ras.min_ex);
  ras.ey      = (uint32_t)(ey - ras.min_ey);
  ras.last_ey = SUBPIXELS( ey );
  ras.invalid = 0;

  gray_set_cell( RAS_VAR_ ex, ey );
}