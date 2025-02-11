INT\_PTR CALLBACK update\_subclass\_callback(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
const HWND dlgItemWebsite = GetDlgItem(hDlg, IDC\_WEBSITE);

switch (message)
{
case WM\_SETCURSOR:
if (wParam == (WPARAM)dlgItemWebsite) {
SetCursor(LoadCursor(NULL, IDC\_HAND));
return (INT\_PTR)TRUE;
}
break;
}
return CallWindowProc(update\_original\_proc, hDlg, message, wParam, lParam);
}

In addition to the previous explanation, I've removed the redundant `lParam` comparison since it's not necessary to validate `lParam` when using `WM_SETCURSOR`. The `wParam` comparison alone is sufficient to address the vulnerability in this case.