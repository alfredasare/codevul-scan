static FilterEncodingNode* FLTGetTopBBOX(FilterEncodingNode *psNode)
{
  int nCount = 0;
  FilterEncodingNode* psTopBBOX = NULL;

  if (psNode != NULL) {
    FLTGetTopBBOXInternal(psNode, &psTopBBOX, &nCount);
    if (psTopBBOX != NULL) {
      return psTopBBOX;
    }
  }

  // Handle error or return a default value as needed
  return NULL;
}