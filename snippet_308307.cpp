XML_SetDefaultHandler(XML_Parser parser,
                      XML_DefaultHandler handler)
{
  if (parser == NULL)
    return;
  defaultHandler = handler;
  defaultExpandInternalEntities = XML_FALSE;
}