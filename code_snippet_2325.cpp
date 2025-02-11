void msPostGISLayerFreeItemInfo(layerObj *layer)
{
#ifdef USE_POSTGIS
  if (layer->debug && layer->iteminfo != NULL) {
    msDebug("msPostGISLayerFreeItemInfo called.\n");
  }

  if (layer->iteminfo != NULL) {
    free(layer->iteminfo);
    layer->iteminfo = NULL;
  }
#endif
}