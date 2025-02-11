FT_Long Current_Ratio( EXEC_OP )
{
  if ( !CUR.tt_metrics.ratio )
  {
#ifdef TT_CONFIG_OPTION_UNPATENTED_HINTING
    if ( CUR.face->unpatented_hinting )
    {
      if ( CUR.GS.both_x_axis )
        CUR.tt_metrics.ratio = CUR.tt_metrics.x_ratio;
      else
        CUR.tt_metrics.ratio = CUR.tt_metrics.y_ratio;
    }
    else
#endif
    {
      if ( CUR.GS.projVector.y == 0 )
      {
        if ( CUR.tt_metrics.x_ratio != 0 )
          CUR.tt_metrics.ratio = CUR.tt_metrics.x_ratio;
        else
          return 0; // or handle this case as appropriate
      }
      else if ( CUR.GS.projVector.x == 0 )
      {
        if ( CUR.tt_metrics.y_ratio != 0 )
          CUR.tt_metrics.ratio = CUR.tt_metrics.y_ratio;
        else
          return 0; // or handle this case as appropriate
      }
      else
      {
        FT_Long  x, y;

        x = TT_MULDIV( CUR.GS.projVector.x,
                       CUR.tt_metrics.x_ratio, 0x4000 );
        y = TT_MULDIV( CUR.GS.projVector.y,
                       CUR.tt_metrics.y_ratio, 0x4000 );
        if ( y != 0 )
          CUR.tt_metrics.ratio = TT_VecLen( x, y );
        else
          return 0; // or handle this case as appropriate
      }
    }
  }
  return CUR.tt_metrics.ratio;
}