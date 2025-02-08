char *FLTGetSpatialComparisonCommonExpression(FilterEncodingNode *psNode, layerObj *lp)
{
  char *pszExpression = NULL;
  shapeObj *psQueryShape = NULL;
  double dfDistance = -1;
  int nUnit = -1, nLayerUnit = -1;
  char *pszWktText = NULL;
  char szBuffer[256];
  char *pszTmp=NULL;
  projectionObj sProjTmp;
  rectObj sQueryRect;
  shapeObj *psTmpShape=NULL;
  int bBBoxQuery = 0;
  int bAlreadyReprojected = 0;

  if (psNode == NULL || lp == NULL)
    return NULL;

  if (psNode->eType != FILTER_NODE_TYPE_SPATIAL)
    return NULL;

  /* get the shape */
  if (FLTIsBBoxFilter(psNode)) {
    char szPolygon[512];
    FLTGetBBOX(psNode, &sQueryRect);

    snprintf(szPolygon, sizeof(szPolygon),
             "POLYGON((%.18f %.18f,%.18f %.18f,%.18f %.18f,%.18f %.18f,%.18f %.18f))",
             sQueryRect.minx, sQueryRect.miny,
             sQueryRect.minx, sQueryRect.maxy,
             sQueryRect.maxx, sQueryRect.maxy,
             sQueryRect.maxx, sQueryRect.miny,
             sQueryRect.minx, sQueryRect.miny);

    psTmpShape = msShapeFromWKT(szPolygon);

    /* 
    ** This is a horrible hack to deal with world-extent requests and
    ** reprojection. msProjectRect() detects if reprojection from longlat to 
    ** projected SRS, and in that case it transforms the bbox to -1e-15,-1e-15,1e15,1e15
    ** to ensure that all features are returned.
    **
    ** Make wfs_200_cite_filter_bbox_world.xml and wfs_200_cite_postgis_bbox_world.xml pass
    */
    if (fabs(sQueryRect.minx - -180.0) < 1e-5 &&
        fabs(sQueryRect.miny - -90.0) < 1e-5 &&
        fabs(sQueryRect.maxx - 180.0) < 1e-5 &&
        fabs(sQueryRect.maxy - 90.0) < 1e-5)
    {
      if (lp->projection.numargs > 0) {
        if (psNode->pszSRS)
          msInitProjection(&sProjTmp);
        if (psNode->pszSRS) {
          /* Use the non EPSG variant since axis swapping is done in FLTDoAxisSwappingIfNecessary */
          if (msLoadProjectionString(&sProjTmp, psNode->pszSRS) == 0) {
            msProjectRect(&sProjTmp, &lp->projection, &sQueryRect);
          }
        } else if (lp->map->projection.numargs > 0)
          msProjectRect(&lp->map->projection, &lp->projection, &sQueryRect);
        if (psNode->pszSRS)
          msFreeProjection(&sProjTmp);
      }
      if (sQueryRect.minx <= -1e14) {
        msFreeShape(psTmpShape);
        msFree(psTmpShape);
        psTmpShape = (shapeObj*) msSmallMalloc(sizeof(shapeObj));
        msInitShape(psTmpShape);
        msRectToPolygon(sQueryRect, psTmpShape);
        bAlreadyReprojected = 1;
      }
    }

    bBBoxQuery = 1;
  } else {
    /* other geos type operations */

    /* project shape to layer projection. If the proj is not part of the filter query,
      assume that the cooredinates are in the map projection */

    psQueryShape = FLTGetShape(psNode, &dfDistance, &nUnit);

    if ((strcasecmp(psNode->pszValue, "DWithin") == 0 || strcasecmp(psNode->pszValue, "Beyond") == 0 ) && dfDistance > 0) {
      nLayerUnit = lp->units;
      if(nLayerUnit == -1) nLayerUnit = GetMapserverUnitUsingProj(&lp->projection);
      if(nLayerUnit == -1) nLayerUnit = lp->map->units;
      if(nLayerUnit == -1) nLayerUnit = GetMapserverUnitUsingProj(&lp->map->projection);

      if (nUnit >= 0 && nUnit != nLayerUnit)
        dfDistance *= msInchesPerUnit(nUnit,0)/msInchesPerUnit(nLayerUnit,0); /* target is layer units */
    }

    psTmpShape = psQueryShape;
  }

  if (psTmpShape) {

    /*
    ** target is layer projection
    */
    if (!bAlreadyReprojected && lp->projection.numargs > 0) {
      if (psNode->pszSRS)
        msInitProjection(&sProjTmp);
      if (psNode->pszSRS) {
        /* Use the non EPSG variant since axis swapping is done in FLTDoAxisSwappingIfNecessary */
        if (msLoadProjectionString(&sProjTmp, psNode->pszSRS) == 0) {
          msProjectShape(&sProjTmp, &lp->projection, psTmpShape);
        }
      } else if (lp->map->projection.numargs > 0)
        msProjectShape(&lp->map->projection, &lp->projection, psTmpShape);
      if (psNode->pszSRS)
        msFreeProjection(&sProjTmp);
    }

    /* function name */
    if (bBBoxQuery) {
      sprintf(szBuffer, "%s", "intersects");
    } else {
      if (strncasecmp(psNode->pszValue, "intersect", 9) == 0)
        sprintf(szBuffer, "%s", "intersects");
      else {
        pszTmp = msStrdup(psNode->pszValue);
        msStringToLower(pszTmp);
        sprintf(szBuffer, "%s", pszTmp);
        msFree(pszTmp);
      }
    }
    pszExpression = msStringConcatenate(pszExpression, szBuffer);
    pszExpression = msStringConcatenate(pszExpression, "(");

    /* geometry binding */
    sprintf(szBuffer, "%s", "[shape]");
    pszExpression = msStringConcatenate(pszExpression, szBuffer);
    pszExpression = msStringConcatenate(pszExpression, ",");

    /* filter geometry */
    pszWktText = msGEOSShapeToWKT(psTmpShape);
    sprintf(szBuffer, "%s", "fromText('");
    pszExpression = msStringConcatenate(pszExpression, szBuffer);
    pszExpression = msStringConcatenate(pszExpression, pszWktText);
    sprintf(szBuffer, "%s", "')");
    pszExpression = msStringConcatenate(pszExpression, szBuffer);
    msGEOSFreeWKT(pszWktText);

    /* (optional) beyond/dwithin distance, always 0.0 since we apply the distance as a buffer earlier */
    if ((strcasecmp(psNode->pszValue, "DWithin") == 0 || strcasecmp(psNode->pszValue, "Beyond") == 0)) {
      sprintf(szBuffer, ",%g", dfDistance);
      pszExpression = msStringConcatenate(pszExpression, szBuffer);      
    }

    /* terminate the function */
    pszExpression = msStringConcatenate(pszExpression, ") = TRUE");
  }

  /*
  ** Cleanup
  */
  if (bBBoxQuery) {
    msFreeShape(psTmpShape);
    msFree(psTmpShape);
  }

  return pszExpression;
}
