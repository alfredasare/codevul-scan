void ContainerNode::parserInsertBefore(PassRefPtr<Node> newChild, Node* nextChild)
{
    //...
    for (auto& child : targets) {
        Node* childNode = child.get();

        insertBeforeCommon(next.get(), childNode);

        childrenChanged(true, nextChildPreviousSibling.get(), nextChild, 1);
        ChildNodeInsertionNotifier(this).notify(childNode);
    }
}