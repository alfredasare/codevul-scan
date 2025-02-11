FT_ULong x, y;

x = TT_SafeMulDiv( CUR.GS.projVector.x, CUR.tt_metrics.x_ratio, 0x4000 );
y = TT_SafeMulDiv( CUR.GS.projVector.y, CUR.tt_metrics.y_ratio, 0x4000 );
CUR.tt_metrics.ratio = TT_VecLen( x, y );