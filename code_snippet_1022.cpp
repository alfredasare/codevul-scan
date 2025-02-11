user_get_local_account (User *user)
{
    // Check if the user input contains any suspicious characters or sequences
    if (strchr(user->input, '..') != NULL) {
        // Return an error or handle the invalid input appropriately
        return INVALID_INPUT;
    }

    // If the input is valid, proceed with the original functionality
    return accounts_user_get_local_account(ACCOUNTS_USER(user));
}