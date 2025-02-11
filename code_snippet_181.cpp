c++
void SerializerMarkupAccumulator::appendEndTag(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->isElementNode() && !shouldIgnoreElement(toElement(node)))
    {
        MarkupAccumulator::appendEndTag(node);
    }
}