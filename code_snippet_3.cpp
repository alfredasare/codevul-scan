void ContainerNode::parserInsertBefore(PassRefPtr<Node> newChild, Node* nextChild)
{
    ASSERT(newChild);
    ASSERT(nextChild);
    ASSERT(nextChild->parentNode() == this);

    // Validate input XML
    if (newChild->nodeType() == Node::DOCUMENT_NODE && newChild->hasChildNodes()) {
        Document* doc = toDocument(newChild.get());
        if (doc->documentElement()->depth() > MAX\_DEPTH || doc->documentElement()->lengthOfAttributeList() > MAX\_LENGTH) {
            // Reject the input due to excessive depth or length
            return;
        }
    }

    NodeVector targets;
    collectTargetNodes(newChild.get(), targets);
    if (targets.isEmpty())
        return;

    if (nextChild->previousSibling() == newChild || nextChild == newChild) // nothing to do
        return;

    RefPtr<Node> next = nextChild;
    RefPtr<Node> nextChildPreviousSibling = nextChild->previousSibling();
    for (NodeVector::const_iterator it = targets.begin(); it != targets.end(); ++it) {
        Node* child = it->get();

        insertBeforeCommon(next.get(), child);

        childrenChanged(true, nextChildPreviousSibling.get(), nextChild, 1);
        ChildNodeInsertionNotifier(this).notify(child);
    }
}

const int MAX\_DEPTH = 100;
const int MAX\_LENGTH = 10000;