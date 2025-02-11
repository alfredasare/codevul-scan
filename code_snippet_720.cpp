String AXObject::recursiveTextAlternative(const AXObject& axObj,
                                          bool inAriaLabelledByTraversal,
                                          AXObjectSet& visited) {
  if (visited.contains(&axObj) && !inAriaLabelledByTraversal)
    return String();

  visited.insert(&axObj); // Add the current object to the visited set

  AXNameFrom tmpNameFrom;
  String result = axObj.textAlternative(true, inAriaLabelledByTraversal, visited,
                                        tmpNameFrom, nullptr, nullptr);

  visited.erase(&axObj); // Remove the current object from the visited set

  return result;
}