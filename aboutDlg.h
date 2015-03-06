#include "resource.h"

#ifndef ABOUTDLG_H_INCLUDED
#define ABOUTDLG_H_INCLUDED

BOOL CALLBACK AboutDlgProc(HWND hwndD, UINT Message, WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
        case WM_INITDIALOG:

        return TRUE;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_OK:
                    EndDialog(hwndD, ID_OK);
                break;
            }
        break;
        default:
            return FALSE;
    }
    return TRUE;
}



#endif // ABOUTDLG_H_INCLUDED
