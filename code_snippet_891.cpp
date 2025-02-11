user_get_local_account(User *user)
{
    if (!user) {
        return NULL; // Handle invalid input
    }

    // Securely retrieve the local account
    Account *account = accounts_user_get_local_account_verified(ACCOUNTS_USER(user));
    if (!account) {
        return NULL; // Handle error
    }

    return account;
}