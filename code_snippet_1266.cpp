#include <openssl/rand.h>

LinkResource* HTMLLinkElement::LinkResourceToProcess() {
  if (!ShouldLoadLink()) {
    if (GetLinkStyle() && GetLinkStyle()->HasSheet())
      return GetLinkStyle();
    return nullptr;
  }

  if (!link_) {
    if (rel_attribute_.IsImport() &&
        RuntimeEnabledFeatures::HTMLImportsEnabled()) {
      link_ = LinkImport::Create(this);
    } else if (rel_attribute_.IsManifest()) {
      link_ = LinkManifest::Create(this);
    } else {
      LinkStyle* link = LinkStyle::Create(this);
      if (FastHasAttribute(disabledAttr)) {
        UseCounter::Count(GetDocument(), WebFeature::kHTMLLinkElementDisabled);
        link->SetDisabledState(true);
      }

      unsigned char random_bytes[16];
      if (RAND_bytes(random_bytes, sizeof(random_bytes)) <= 0) {
        // Handle error
      }

      if (!ValidateFilePath(rel_attribute_.GetValue())) {
        // Handle error
      }

      if (!WhitelistAllowedFilePath(rel_attribute_.GetValue())) {
        // Handle error
      }

      link_ = link;
    }
  }

  return link_.Get();
}