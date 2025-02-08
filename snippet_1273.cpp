  cf2_glyphpath_lineTo( CF2_GlyphPath  glyphpath,
                        CF2_Fixed      x,
                        CF2_Fixed      y )
  {
    CF2_Fixed  xOffset, yOffset;
    FT_Vector  P0, P1;
    FT_Bool    newHintMap;

    /*
     * New hints will be applied after cf2_glyphpath_pushPrevElem has run.
     * In case this is a synthesized closing line, any new hints should be
     * delayed until this path is closed (`cf2_hintmask_isNew' will be
     * called again before the next line or curve).
     */

    /* true if new hint map not on close */
    newHintMap = cf2_hintmask_isNew( glyphpath->hintMask ) &&
                 !glyphpath->pathIsClosing;

    /*
     * Zero-length lines may occur in the charstring.  Because we cannot
     * compute darkening offsets or intersections from zero-length lines,
     * it is best to remove them and avoid artifacts.  However, zero-length
     * lines in CS at the start of a new hint map can generate non-zero
     * lines in DS due to hint substitution.  We detect a change in hint
     * map here and pass those zero-length lines along.
     */

    /*
     * Note: Find explicitly closed paths here with a conditional
     *       breakpoint using
     *
     *         !gp->pathIsClosing && gp->start.x == x && gp->start.y == y
     *
     */

    if ( glyphpath->currentCS.x == x &&
         glyphpath->currentCS.y == y &&
         !newHintMap                 )
      /*
       * Ignore zero-length lines in CS where the hint map is the same
       * because the line in DS will also be zero length.
       *
       * Ignore zero-length lines when we synthesize a closing line because
       * the close will be handled in cf2_glyphPath_pushPrevElem.
       */
      return;

    cf2_glyphpath_computeOffset( glyphpath,
                                 glyphpath->currentCS.x,
                                 glyphpath->currentCS.y,
                                 x,
                                 y,
                                 &xOffset,
                                 &yOffset );

    /* construct offset points */
    P0.x = glyphpath->currentCS.x + xOffset;
    P0.y = glyphpath->currentCS.y + yOffset;
    P1.x = x + xOffset;
    P1.y = y + yOffset;

    if ( glyphpath->moveIsPending )
    {
      /* emit offset 1st point as MoveTo */
      cf2_glyphpath_pushMove( glyphpath, P0 );

      glyphpath->moveIsPending = FALSE;  /* adjust state machine */
      glyphpath->pathIsOpen    = TRUE;

      glyphpath->offsetStart1 = P1;              /* record second point */
    }

    if ( glyphpath->elemIsQueued )
    {
      FT_ASSERT( cf2_hintmap_isValid( &glyphpath->hintMap ) );

      cf2_glyphpath_pushPrevElem( glyphpath,
                                  &glyphpath->hintMap,
                                  &P0,
                                  P1,
                                  FALSE );
    }

    /* queue the current element with offset points */
    glyphpath->elemIsQueued = TRUE;
    glyphpath->prevElemOp   = CF2_PathOpLineTo;
    glyphpath->prevElemP0   = P0;
    glyphpath->prevElemP1   = P1;

    /* update current map */
    if ( newHintMap )
      cf2_hintmap_build( &glyphpath->hintMap,
                         glyphpath->hStemHintArray,
                         glyphpath->vStemHintArray,
                         glyphpath->hintMask,
                         glyphpath->hintOriginY,
                         FALSE );

    glyphpath->currentCS.x = x;     /* pre-offset current point */
    glyphpath->currentCS.y = y;
  }
