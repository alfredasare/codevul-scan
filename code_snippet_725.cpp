#include <vector>

void fillRelationships(AXObject& axObject,
                       protocol::Array<AXProperty>& properties) {
  std::vector<AXObject*> results;

  axObject.ariaDescribedbyElements(results);
  if (!results.empty()) {
    // Perform input validation here
    properties.addItem(
        createRelatedNodeListProperty(AXRelationshipAttributesEnum::Describedby,
                                      results, aria_describedbyAttr, axObject));
  }
  results.clear();

  axObject.ariaOwnsElements(results);
  if (!results.empty()) {
    // Perform input validation here
    properties.addItem(createRelatedNodeListProperty(
        AXRelationshipAttributesEnum::Owns, results, aria_ownsAttr, axObject));
  }
  results.clear();
}