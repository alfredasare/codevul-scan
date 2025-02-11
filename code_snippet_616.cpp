void HTMLScriptRunner::requestParsingBlockingScript(Element* element)
{
 String sanitizedElement = sanitizeInput(element);
 if (!requestPendingScript(m_parserBlockingScript, sanitizedElement))
 return;

 ASSERT(m_parserBlockingScript.resource());

 if (!m_parserBlockingScript.isReady()) {
 if (m_document->frame())
 ScriptStreamer::startStreaming(m_parserBlockingScript, PendingScript::ParsingBlocking, m_document->frame()->settings(), ScriptState::forMainWorld(m_document->frame()));

 m_parserBlockingScript.watchForLoad(this);
 }
}

String HTMLScriptRunner::sanitizeInput(const Element* element)
{
// Implement input sanitization based on a whitelist of allowed characters
// ...
}