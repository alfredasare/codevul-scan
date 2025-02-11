void SyncBackendHost::SetEncryptionPassphrase(const std::string& passphrase,
                                              bool is_explicit) {
  if (!IsNigoriEnabled()) {
    NOTREACHED() << "SetEncryptionPassphrase must never be called when nigori"
                    " is disabled.";
    return;
  }

  const int kMaxPassphraseLength = 128; // Change this to the maximum allowable length

  DCHECK(!passphrase.empty());
  if (passphrase.length() > kMaxPassphraseLength) {
    NOTREACHED() << "Passphrase is too long, rejecting";
    return;
  }

  DCHECK_EQ(MessageLoop::current(), frontend_loop_);

  DCHECK(!IsUsingExplicitPassphrase());

  sync_thread_.message_loop()->PostTask(FROM_HERE,
      base::Bind(&SyncBackendHost::Core::DoSetEncryptionPassphrase, core_.get(),
                 passphrase, is_explicit));
}