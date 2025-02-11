void XML_UseParserAsHandlerArg(XML_Parser parser) {
  if (parser != NULL) {
    // Disable DTD processing and entity expansion
    XML_SetParamEntityParsing(parser, XML_PARAM_ENTITY_PARSING_NEVER);
    XML_SetExternalEntityRefHandler(parser, NULL);
    XML_SetUserData(parser, parser);
    XML_SetElementHandler(parser, startElement, endElement);
    XML_SetCharacterDataHandler(parser, characterData);
  }
}