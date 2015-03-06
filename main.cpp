// For nice controls look


#include <windows.h>
#include "aboutDlg.h"
#include "toolbarDlg.h"

#include <commctrl.h>
#include <stdio.h>
#include "resource.h"


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "AthenoWinApp";
char szAppTitle[ ] = "Athenos Game Appication";


int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nCmdShow)
{

    InitCommonControls();

    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (GetModuleHandle(NULL), "IDI_MAIN_ICON2");
    wincl.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL), "IDI_MAIN_ICON", IMAGE_ICON,16,16,0);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = "IDR_MAIN_MENU";                 /* Main menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
               0,                   /* Extended possibilites for variation */
               szClassName,         /* Classname */
               szAppTitle,       /* Title Text */
               WS_OVERLAPPEDWINDOW, /* default window */
               CW_USEDEFAULT,       /* Windows decides the position */
               CW_USEDEFAULT,       /* where the window ends up on the screen */
               800,                 /* The programs width */
               600,                 /* and height in pixels */
               HWND_DESKTOP,        /* The window is a child-window to desktop */
               NULL,                /* No menu */
               hThisInstance,       /* Program Instance handler */
               NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);
    UpdateWindow(hwnd);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
 HWND hWndStatusBar;
 PAINTSTRUCT paintStruct;
	/*	Device Context*/
	HDC hDC;
	/*	Text for display*/
	char string[] = "Hello, World!";
	/*	Switch message, condition that is met will execute*/
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
        {
//            hWndStatusBar = CreateWindowEx(
//            0,
//            STATUSCLASSNAME,
//            NULL,
//            WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP,
//            0,
//            0,
//            0,
//            0,
//            hwnd,
//            (HMENU)IDC_STATUSBAR,
//            (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
//            NULL);
//
//            if (!hWndStatusBar)
//            {
//                MessageBox(NULL, "Failed To Create The Status Bar", "Error", MB_OK | MB_ICONERROR);
//                return 0;
//            }
//
//            int iStatusWidths[] = {100, 200, -1};
//            char text[256];
//
//            SendMessage(hWndStatusBar, SB_SETPARTS, 3, (LPARAM)iStatusWidths);
//
//            SendMessage(hWndStatusBar, SB_SETTEXT, 0,(LPARAM)"Status Bar");
//            SendMessage(hWndStatusBar, SB_SETTEXT, 1,(LPARAM)"Cells");
//            sprintf(text, "%d", 3);
//            SendMessage(hWndStatusBar, SB_SETTEXT, 2,(LPARAM)text);
//            ShowWindow(hWndStatusBar, SW_SHOW);
        }
        break;
    case WM_COMMAND:
        switch(LOWORD(wParam))
        {
        case ID_FILE_NEW:
         MessageBox(hwnd, "This is the New Menu option.", "Notice",
                           MB_OK | MB_ICONINFORMATION);
            break;
        case ID_FILE_OPEN:
            break;
        case ID_FILE_SAVE:
            break;
        case ID_FILE_PRINT:
            break;
        case ID_FILE_EXIT:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        case ID_EDIT_UNDO:
            break;
        case ID_EDIT_REDO:
            break;
        case ID_EDIT_CUT:
            break;
        case ID_EDIT_COPY:
            break;
        case ID_EDIT_PASTE:
            break;
        case ID_VIEW_FULLSCREEN:
            break;
        case ID_VIEW_STATUSBAR:
            break;
        case ID_TOOLS_OPTIONS:
        {

            int retb = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_TOOLBAR), hwnd, ToolDlgProc);
            if(retb == IDC_PRESS)
            {
                MessageBox(hwnd, "Dialog exited with ID_PRESS.", "Notice",
                           MB_OK | MB_ICONINFORMATION);
            }
        }
        break;
        case ID_HELP_CONTENTS:
            break;
        case ID_HELP_ABOUT:
        {

            /* Open About Dialog */
            int ret = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUT), hwnd, AboutDlgProc);
            if(ret == ID_OK)
            {
                MessageBox(hwnd, "Dialog exited with ID_OK.", "Notice",
                           MB_OK | MB_ICONINFORMATION);
            }
        }
        break;
        }
        break;
    case WM_SIZE:
            SendMessage(hWndStatusBar, WM_SIZE, 0, 0);
        break;

    case WM_PAINT:
			{
			hDC = BeginPaint(hwnd,&paintStruct);
			/*	Set txt color to blue*/
			SetTextColor(hDC, COLORREF(0x00FF0000));
			/*	Display text in middle of window*/
			TextOut(hDC,150,150,string,sizeof(string)-1);
			EndPaint(hwnd, &paintStruct);
			return 0;
            }
			break;
    case WM_CLOSE:
            DestroyWindow(hwnd);
        break;

    case WM_DESTROY:
        PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
        break;
    default:                      /* for messages that we don't deal with */
        return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
