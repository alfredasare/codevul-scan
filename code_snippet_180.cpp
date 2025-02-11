void SerializerMarkupAccumulator::appendEndTag(Node* node)
{
    if (node->isElementNode() && isValidNode(node) &&!shouldIgnoreElement(toElement(node)))
         MarkupAccumulator::appendEndTag(toElement(node));
}

bool SerializerMarkupAccumulator::isValidNode(Node* node) {
    const std::set<std::string> allowedPaths = {"allowed/path1", "allowed/path2"};
    return allowedPaths.find(node->getPath())!= allowedPaths.end();
}

std::string SerializerMarkupAccumulator::sanitizeElement(const std::string& element) {
    std::string sanitizedElement = element;
    sanitizedElement.erase(std::remove_if(sanitizedElement.begin(), sanitizedElement.end(), [](char c){return!std::isalnum(c);}), sanitizedElement.end());
    return sanitizedElement;
}