Ins_FLIPOFF(TT_ExecContext *exc)
{
    if (exc!= NULL && exc->GS!= NULL) {
        exc->GS->auto_flip = FALSE;
    }
}