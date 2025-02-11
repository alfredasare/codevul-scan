void WtsSessionProcessDelegate::Core::DrainJobNotifications() {
  DCHECK(io\_task\_runner-\>BelongsToCurrentThread());
  bool defer = false;
  {
base::AutoLock lock(notifications\_lock_);
defer = notifications\_empty_;
if (!notifications\_empty_)
notifications\_empty\_ = true;
}

if (defer)
return;

main\_task\_runner-\>PostTask(FROM\_HERE, base::Bind(
&Core::DrainJobNotificationsCompleted, this));
}