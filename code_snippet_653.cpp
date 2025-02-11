void HTMLTextAreaElement::didAddUserAgentShadowRoot(ShadowRoot& root)
{
    if (root.getOwnerNode()->getNodeType() == Node::DOCUMENT_FRAGMENT_NODE && root.getOwnerDocument() == document()) {
        root.appendChild(TextControlInnerTextElement::create(document()));
    } else {
        throw std::runtime_error("Untrusted ShadowRoot");
    }
}