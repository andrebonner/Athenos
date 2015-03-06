#include "resource.h"

#ifndef TOOLBARDLG_H_INCLUDED
#define TOOLBARDLG_H_INCLUDED

BOOL CALLBACK ToolDlgProc(HWND hwndD, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
        case WM_INITDIALOG:

        return TRUE;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case IDC_PRESS:
                    MessageBox(hwndD, "Hi!", "This is a message",
                        MB_OK | MB_ICONEXCLAMATION);
                         EndDialog(hwndD, IDC_PRESS);
                break;
                case IDC_OTHER:
                    MessageBox(hwndD, "Bye!", "This is also a message",
                        MB_OK | MB_ICONEXCLAMATION);
                        EndDialog(hwndD, NULL);
                break;
            }
        break;
        case WM_DESTROY:

            break;
        default:
            return FALSE;
    }
    return TRUE;
}


#endif // TOOLBARDLG_H_INCLUDED
