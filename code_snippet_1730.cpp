OneClickSigninSyncStarter::OneClickSigninSyncStarter(
    Profile* profile,
    Browser* browser,
    const std::string& session_index,
    const AccountInfo& account_info,
    StartSyncMode start_mode,
    bool force_same_tab_navigation,
    ConfirmationRequired confirmation_required)
    : start_mode_(start_mode),
      force_same_tab_navigation_(force_same_tab_navigation),
      confirmation_required_(confirmation_required),
      weak_pointer_factory_(this) {
  DCHECK(profile);
  BrowserList::AddObserver(this);

  Initialize(profile, browser);

  SigninManager* manager = SigninManagerFactory::GetForProfile(profile_);
  SigninManager::OAuthTokenFetchedCallback callback;
  callback = base::Bind(&OneClickSigninSyncStarter::ConfirmSignin,
                        weak_pointer_factory_.GetWeakPtr(), account_info);
  manager->StartSignInWithCredentials(session_index, account_info.email, account_info.password_hash, callback);
}