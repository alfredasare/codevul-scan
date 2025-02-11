psh_compute_dir( FT_Pos  dx,
                 FT_Pos  dy )
{
    FT_Pos  ax, ay;
    int     result = PSH_DIR_NONE;

    // Validate and sanitize input values
    dx = ( dx > 0 )? dx : 0;
    dy = ( dy > 0 )? dy : 0;

    ax = ( dx >= 0 )? dx : -dx;
    ay = ( dy >= 0 )? dy : -dy;

    if ( ay * 12 < ax )
    {
        //...
    }
    else if ( ax * 12 < ay )
    {
        //...
    }

    return result;
}