#include <windows.h>
#include <CommCtrl.h>
 
#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif
 
#define IDD_DIALOG1                     10113
#define IDB_BITMAP1                     10114
#define IDB_BITMAP2                     6105
#define IDI_ICON_LOVE                   4101
#define IDR_MENU_MAIN                   4012
#define ID_HELP_ABOUT                   4107
#define ID_ABOUT                        4108
#define ID_FILE_QUIT                    4019
#define IDI_ICON_LOVE1                  4001
#define IMG_TILEMYLOVE                  5001
#define ID_ABOUT_SOFT                   40009
#define ID_FILE_NEW1                    40010
#define ID_FILE_OPEN1                   40011
 
#define IDC_MAIN_GROUP_INFO         101
#define IDC_MAIN_EDITNAME           102
#define IDC_MAIN_COMBO_COUNTRY      103
#define IDC_MAIN_GROUP_SEX          104
#define IDC_MAIN_SEX_MALE           105
#define IDC_MAIN_SEX_FEMALE         106
#define IDC_MAIN_GROUP_FAVORITE     107
#define IDC_MAIN_FAVORITE_SOCCER    108
#define IDC_MAIN_FAVORITE_MUSIC     109
#define IDC_MAIN_FAVORITE_PICPIC    110
#define IDC_MAIN_FAVORITE_OTHERS    111
#define IDC_MAIN_BUTTON_HIENTHI     112
#define IDC_MAIN_GROUP_RESULT       113
#define IDC_MAIN_EDITTEXT_RESULT    114
 
 
static  HWND hWndGroupNhapThongTin;
static  HWND hEditName;
static  HWND hWndComboQuequan;
static  HWND hWndGroupGioitinh;
static  HWND hWndButtonRadioNam;
static  HWND hWndButtonRadioNu;
static  HWND hWndGroupSothich;
static  HWND hWndButtonBongda;
static  HWND hWndButtonCanhac;
static  HWND hWndButtonDangoai;
static  HWND hWndButtonLoaikhac;
static  HWND hWndButtonHienthi;
static  HWND hWndGroupKetqua;
static  HWND hEditResult;
 
/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
    switch(Message) {
         
        /* Upon destruction, tell the main thread to stop */
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
         
        /* All other messages (a lot of them) are processed using default procedures */
        default:
            return DefWindowProc(hwnd, Message, wParam, lParam);
    }
    return 0;
}
 
/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc; /* A properties struct of our window */
    HWND hWnd; /* A 'HANDLE', hence the H, or a pointer to our window */
     
     
    MSG msg; /* A temporary location for all messages */
 
    /* zero out the struct and set the stuff we want to modify */
    memset(&wc,0,sizeof(wc));
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.lpfnWndProc   = WndProc; /* This is where we will send messages to */
    wc.hInstance     = hInstance;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
     
    /* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszClassName = "WindowClass";
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */
 
    if(!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
        return 0;
    }
 
    hWnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Server Chat",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, /* x */
        CW_USEDEFAULT, /* y */
        608, /* width */
        608, /* height */
        NULL,NULL,hInstance,NULL);
 
    if(hWnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
        return 0;
    }
 
    hWndGroupNhapThongTin=CreateWindowEx(NULL, 
                "BUTTON",
                "Nhap thong tin",
                WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_GROUPBOX,
                10,
                40,
                230,
                400,
                hWnd,
                (HMENU)IDC_MAIN_EDITNAME,
                GetModuleHandle(NULL),
                NULL);
     
    hEditName=CreateWindowEx(WS_EX_CLIENTEDGE,
                "EDIT",
                "",
                WS_CHILD|WS_VISIBLE|ES_MULTILINE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,
                20,
                70,
                200,
                25,
                hWnd,
                (HMENU)IDC_MAIN_EDITNAME,
                GetModuleHandle(NULL),
        NULL);
 
 
    hWndComboQuequan = CreateWindow(WC_COMBOBOX, "", 
        CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
        20, 100, 200, 500, hWnd, (HMENU)IDC_MAIN_COMBO_COUNTRY, HINST_THISCOMPONENT,
        NULL);
 
    TCHAR Quequans[9][30] =  
    {
        TEXT("Nghe An"), TEXT("Ha Tinh"), TEXT("Quang Binh"), TEXT("Quang Tri"), 
        TEXT("Thua Thien Hue"), TEXT("Da Nang"), TEXT("Vung Tau"), TEXT("Ho Chi Minh"), 
        TEXT("Ha Noi") 
    };
 
    TCHAR A[100]; 
    int  k = 0; 
 
    memset(&A,0,sizeof(A));  
 
    for (k = 0; k <= 8; k += 1)
    {
        wcscpy((wchar_t*)A,  (wchar_t*)Quequans[k]);
 
        // Add string to combobox.
        SendMessage(hWndComboQuequan,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) A); 
    }
 
    // Send the CB_SETCURSEL message to display an initial item 
    //  in the selection field  
    SendMessage(hWndComboQuequan, CB_SETCURSEL, (WPARAM)2, (LPARAM)0);
 
    //SendMessage(hWndComboQuequan, CB_SHOWDROPDOWN, (WPARAM)(BOOL)true,0);
    hWndGroupGioitinh=CreateWindowEx(NULL, 
        "BUTTON",
        "Gioi tinh",
        WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_GROUPBOX,
        20,
        125,
        200,
        70,
        hWnd,
        (HMENU)IDC_MAIN_GROUP_SEX,
        GetModuleHandle(NULL),
        NULL);
 
 
 
    hWndButtonRadioNam=CreateWindowEx(NULL, 
        "BUTTON",
        "Nam",
        WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_AUTORADIOBUTTON,
        25,
        140,
        100,
        24,
        hWnd,
        (HMENU)IDC_MAIN_SEX_MALE,
        GetModuleHandle(NULL),
        NULL);
 
 
    hWndButtonRadioNu=CreateWindowEx(NULL, 
        "BUTTON",
        "Nu",
        WS_VISIBLE|WS_CHILD|BS_AUTORADIOBUTTON,
        25,
        160,
        100,
        24,
        hWnd,
        (HMENU)IDC_MAIN_SEX_FEMALE,
        GetModuleHandle(NULL),
        NULL);
 
    hWndGroupSothich=CreateWindowEx(NULL, 
        "BUTTON",
        "So thich",
        WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_GROUPBOX,
        20,
        200,
        200,
        200,
        hWnd,
        (HMENU)IDC_MAIN_GROUP_FAVORITE,
        GetModuleHandle(NULL),
        NULL);
 
    hWndButtonBongda=CreateWindowEx(NULL, 
        "BUTTON",
        "Bong da",
        WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_AUTOCHECKBOX,
        30,
        220,
        100,
        24,
        hWnd,
        (HMENU)IDC_MAIN_FAVORITE_SOCCER,
        GetModuleHandle(NULL),
        NULL);
 
    hWndButtonCanhac=CreateWindowEx(NULL, 
        "BUTTON",
        "Ca nhac",
        WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_AUTOCHECKBOX,
        30,
        250,
        100,
        24,
        hWnd,
        (HMENU)IDC_MAIN_FAVORITE_MUSIC,
        GetModuleHandle(NULL),
        NULL);
 
    hWndButtonDangoai=CreateWindowEx(NULL, 
        "BUTTON",
        "Da ngoai",
        WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_AUTOCHECKBOX,
        30,
        280,
        100,
        24,
        hWnd,
        (HMENU)IDC_MAIN_FAVORITE_PICPIC,
        GetModuleHandle(NULL),
        NULL);
 
    hWndButtonLoaikhac=CreateWindowEx(NULL, 
        "BUTTON",
        "Loai khac",
        WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_AUTOCHECKBOX,
        30,
        310,
        100,
        24,
        hWnd,
        (HMENU)IDC_MAIN_FAVORITE_OTHERS,
        GetModuleHandle(NULL),
        NULL);
 
    hWndButtonHienthi=CreateWindowEx(NULL, 
        "BUTTON",
        "Hien thi",
        WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_PUSHBUTTON,
        180,
        460,
        200,
        24,
        hWnd,
        (HMENU)IDC_MAIN_BUTTON_HIENTHI,
        GetModuleHandle(NULL),
        NULL);
 
    //Create result
 
    hWndGroupKetqua=CreateWindowEx(NULL, 
        "BUTTON",
        "Ket qua",
        WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_GROUPBOX,
        250,
        40,
        300,
        400,
        hWnd,
        (HMENU)IDC_MAIN_GROUP_RESULT,
        GetModuleHandle(NULL),
        NULL);
 
    hEditResult=CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT","Thong tin nguoi dung:",
        WS_CHILD|WS_VISIBLE|ES_MULTILINE|ES_AUTOVSCROLL|ES_AUTOHSCROLL|ES_READONLY,
        260,
        70,
        280,
        200,
        hWnd,
        (HMENU)IDC_MAIN_EDITTEXT_RESULT,
        GetModuleHandle(NULL),
        NULL);          
    /*
        This is the heart of our program where all input is processed and 
        sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
        this loop will not produce unreasonably high CPU usage
    */
    while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
        TranslateMessage(&msg); /* Translate key codes to chars if present */
        DispatchMessage(&msg); /* Send it to WndProc */
    }
    return msg.wParam;
}