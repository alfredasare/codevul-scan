bool BlockEntry::EOS() const {
return (GetKind() == kBlockEOS && static_cast<int>(GetKind()) < static_cast<int>(kBlockMax));
}