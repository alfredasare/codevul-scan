#define MAX_ALLOWED_INDEX 10 // Replace this with the appropriate maximum index value

Ins_SZPS( INS_ARG )
{
  // Validate args[0] is within the bounds of a valid index
  if (args[0] < 0 || args[0] >= MAX_ALLOWED_INDEX) {
    if (CUR.pedantic_hinting)
      CUR.error = TT_Err_Invalid_Reference;
    return;
  }

  switch ( (FT_Int)args[0] )
  {
    case 0:
      CUR.zp0 = CUR.twilight;
      break;

    case 1:
      CUR.zp0 = CUR.pts;
      break;

    default:
      if ( CUR.pedantic_hinting )
        CUR.error = TT_Err_Invalid_Reference;
      return;
  }

  CUR.zp1 = CUR.zp0;
  CUR.zp2 = CUR.zp0;

  CUR.GS.gep0 = (FT_UShort)args[0];
  CUR.GS.gep1 = (FT_UShort)args[0];
  CUR.GS.gep2 = (FT_UShort)args[0];
}