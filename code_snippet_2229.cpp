void ScriptLoader::execute(ScriptResource* resource)
{
    ASSERT(!m_willBeParserExecuted);
    ASSERT(resource);
    if (resource->errorOccurred()) {
        dispatchErrorEvent();
    } else if (!resource->wasCanceled()) {
        executeScript(ScriptSourceCode(*resource)); // Pass a copy of the resource to the executeScript method
        dispatchLoadEvent();
    }
    resource->removeClient(this);
}