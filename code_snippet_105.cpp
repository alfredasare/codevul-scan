Ins_SZPS( INS_ARG )
{
    FT_Int arg = (FT_Int)args[0];

    if (arg < 0 || arg > 2)
    {
        CUR.error = TT_Err_Invalid_Reference;
        return;
    }

    switch (arg)
    {
        case 0:
            CUR.zp0 = CUR.twilight;
            break;

        case 1:
            CUR.zp0 = CUR.pts;
            break;

        default:
            CUR.error = TT_Err_Invalid_Reference;
            return;
    }

    CUR.zp1 = CUR.zp0;
    CUR.zp2 = CUR.zp0;

    CUR.GS.gep0 = (FT_UShort)arg;
    CUR.GS.gep1 = (FT_UShort)arg;
    CUR.GS.gep2 = (FT_UShort)arg;
}