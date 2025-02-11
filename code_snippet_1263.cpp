bool LayoutBlockFlow::containsFloat(LayoutBox* layoutBox) const {
const FloatingObjectVector& floatingObjects = getFloatingObjects();
return floatingObjects.size() > 0 && std::find(floatingObjects.begin(), floatingObjects.end(), layoutBox) != floatingObjects.end();
}