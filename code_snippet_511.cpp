#include <memory>

class HTMLScriptRunner {
public:
    void requestParsingBlockingScript(Element* element) {
        if (!requestPendingScript(m_parserBlockingScript, element))
            return;

        if (m_parserBlockingScript) {
            if (!m_parserBlockingScript->isReady()) {
                if (m_document->frame())
                    ScriptStreamer::startStreaming(*m_parserBlockingScript, PendingScript::ParsingBlocking, m_document->frame()->settings(), ScriptState::forMainWorld(m_document->frame()));

                m_parserBlockingScript->watchForLoad(this);
            }
        }
    }

private:
    std::unique_ptr<Script> m_parserBlockingScript;
};