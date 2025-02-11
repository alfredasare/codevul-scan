LinkResource* HTMLLinkElement::LinkResourceToProcess() {
  if (!ShouldLoadLink()) {
    if (GetLinkStyle() && GetLinkStyle()->HasSheet())
      return GetLinkStyle();
    return nullptr;
  }

  if (!link_) {
    std::unique_ptr<LinkResource> new_link;
    if (rel_attribute_.IsImport() &&
        RuntimeEnabledFeatures::HTMLImportsEnabled()) {
      new_link.reset(LinkImport::Create(this));
    } else if (rel_attribute_.IsManifest()) {
      new_link.reset(LinkManifest::Create(this));
    } else {
      LinkStyle* link = LinkStyle::Create(this);
      if (FastHasAttribute(disabledAttr)) {
        UseCounter::Count(GetDocument(), WebFeature::kHTMLLinkElementDisabled);
        link->SetDisabledState(true);
      }
      new_link.reset(link);
    }
    link_ = std::move(new_link);
  }

  return link_.get();
}