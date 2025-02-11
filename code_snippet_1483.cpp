INT_PTR CALLBACK update_subclass_callback(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_SETCURSOR:
        if ((HWND)wParam == GetDlgItem(hDlg, IDC_WEBSITE))
        {
            PCWSTR sanitizedParam = ValidateAndSanitizeFormatString((PCWSTR)wParam);
            SetCursor(LoadCursor(NULL, IDC_HAND));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return CallWindowProc(update_original_proc, hDlg, message, wParam, lParam);
}

PCWSTR ValidateAndSanitizeFormatString(PCWSTR formatString)
{
    // Implement your own validation and sanitization logic here
    // For example, you can check if the format string contains any malicious characters
    // or if it exceeds a certain length.
    return formatString;
}