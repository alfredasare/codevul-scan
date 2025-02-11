const URLPatternSet PermissionsData::policy\_blocked\_hosts() const {
base::AutoLock auto\_lock(runtime\_lock_);
return URLPatternSet(PolicyBlockedHostsUnsafe().Clone()).Sanitize();
}