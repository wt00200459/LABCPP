#include<windows.h>
#include<tchar.h>

//Global Variables:
HINSTANCE hInst;		// current instance
TCHAR szTitle[]="Easywin32";		//The title bar text
TCHAR szWindowClass[]="WinApp";		//the class name
BOOL 		fDraw = FALSE; 
POINT		 ptPrevious; 
TEXTMETRIC tm; 
#define BUFSIZE 65535 
         // structure for text metrics 
    static DWORD dwCharX;      // average width of characters 
    static DWORD dwCharY;      // height of characters 
    static DWORD dwClientX;    // width of client area 
    static DWORD dwClientY;    // height of client area 
    static DWORD dwLineLen;    // line length 
    static DWORD dwLines;      // text lines in client area 
    static int nCaretPosX = 0; // horizontal position of caret 
    static int nCaretPosY = 0; // vertical position of caret 
    static int nCharWidth = 0; // width of a character 
    static int cch = 0;        // characters in buffer 
    static int nCurChar = 0;   // index of current character 
    static PTCHAR pchInputBuf; // input buffer 
    int i, j;                  // loop counters 
    int cCR = 0;               // count of carriage returns 
    int nCRIndex = 0;          // index of last carriage return 
    int nVirtKey;              // virtual-key code 
    TCHAR szBuf[128];          // temporary buffer 
    TCHAR ch;                  // current character 
    PAINTSTRUCT ps;            // required by BeginPaint 
    RECT rc;                   // output rectangle for DrawText 
    SIZE sz;                   // string dimensions 
    COLORREF crPrevText;       // previous text color 
    COLORREF crPrevBk;         // previous background color
	size_t * pcch;
	HRESULT hResult; 
 int Index ;
COLORREF Color[]={RGB(255,0,0),RGB(0,255,0),RGB(0,0,255),RGB(0,0,0)};
//Foward declarations of funtions included in this code module:
ATOM			MyRegisterClass(HINSTANCE hInstance);
BOOL			InitInstance(HINSTANCE, int);

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
			HINSTANCE hPrevInstance,
			LPSTR	  lpCmdLine,
			int		nCmdShow)
{
		//TODO:Place code here.
		MSG msg;
		//Register Class
		MyRegisterClass(hInstance);
		
		//Perfome application initialization:
		if(!InitInstance (hInstance,nCmdShow))
		{
			return FALSE;
		}
		
		//Main message loop:
		while(GetMessage(&msg,NULL,0,0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
		return msg.wParam;
}



//
// FUNCTION:MyRegisterClass()
//
// PURPOSE:Register the window class.
//
// COMMENTS
//
// This funtion and its usage is only neccessary if you want code
// to be compatible with Win32 systems prioi to the 'RegisterClassEx'
// function that was added to Windows 95.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{ 
	WNDCLASSEX wcex;
	
	wcex.cbSize=sizeof(WNDCLASSEX);
	
	wcex.style		=CS_HREDRAW|CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra	= 0;
	wcex.hInstance	= hInstance;
	wcex.hIcon		= LoadIcon(NULL,IDI_APPLICATION);
	wcex.hCursor	=LoadCursor(NULL,IDC_ARROW);
	wcex.hbrBackground =(HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName  =NULL;
	wcex.lpszClassName =szWindowClass;
	wcex.hIconSm	   =LoadIcon(NULL,IDI_APPLICATION);
	
	return RegisterClassEx(&wcex);
}

//
// FUNCION:InitInstance(HAMDLE,int)
//
// PURPOSE:Saves instance handle and creates main window
//
// COMMENTS:
//
//	In this function, we save the instance handle in a global variable and
//	 create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	
	hInst = hInstance;// Store instance handle in our global variable
	hWnd = CreateWindow(szWindowClass,szTitle,WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,0,CW_USEDEFAULT,0,NULL,NULL,hInstance,
		NULL);
		
		
		if(!hWnd)
		{
			return FALSE;
		}
	
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);
	
	return TRUE;
}

//
// FUNCTION:WndProc(HWND,unsigned,WORD,LONG)
//
// PURPOSE: Processes messages for the main window.
//
// WM_COMMAND   -process the application menu
// WM_PAINT     -Paint the main window
// WM_destroy -post a quit message and return
//
//

void Marker(LONG x, LONG y, int Index, HWND hwnd)
{
	HDC hdc;
		HPEN hPen;
	hdc = GetDC(hwnd);
		hPen = CreatePen(PS_DOT,1,Color[Index]);
	SelectObject(hdc, hPen);
	MoveToEx(hdc, (int) x - 10, (int) y , (LPPOINT)NULL);
	LineTo(hdc, (int) x + 10, (int) y);
	MoveToEx(hdc, (int) x, (int) y -10, (LPPOINT)NULL);
	LineTo(hdc, (int) x,(int) y + 10);
		DeleteObject(hPen);
	ReleaseDC(hwnd, hdc);
}


LRESULT CALLBACK WndProc(HWND hWnd,UINT message, WPARAM 
		wParam,LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	HPEN hPen;
	RECT rt;
	char szHello[]="Hello,C-Free!";
	 
	
	
	switch(message)
	{
			case WM_PAINT:
				hdc = BeginPaint(hWnd, &ps);
				//TODO:Add any Drawing code here...
				
				GetClientRect(hWnd,&rt);
				DrawText(hdc,szHello,strlen(szHello),&rt,DT_CENTER);
				Marker(50,50,Index,hWnd);
				EndPaint(hWnd,&ps);
				break;
			case WM_CLOSE:
				DestroyWindow(hWnd);
				break;
			
			case WM_DESTROY:
				PostQuitMessage(0);
				break;
	case WM_LBUTTONDOWN: 
    fDraw = TRUE; 
    ptPrevious.x = LOWORD(lParam); 
    ptPrevious.y = HIWORD(lParam); 
    return 0L; 
 
case WM_LBUTTONUP: 
    if (fDraw) 
    { 
        hdc = GetDC(hWnd);
		   	hPen = CreatePen(PS_DOT,5,Color[Index]);
      SelectObject(hdc, hPen);
	
        MoveToEx(hdc, ptPrevious.x, ptPrevious.y, NULL); 
         
        LineTo(hdc, LOWORD(lParam), HIWORD(lParam)); 
        ReleaseDC(hWnd, hdc); 
    } 
    fDraw = FALSE; 
    return 0L; 
 
case WM_MOUSEMOVE: 
    if (fDraw) 
    { 
        hdc = GetDC(hWnd); 
		hPen = CreatePen(PS_DOT,5,Color[Index]);
		 SelectObject(hdc, hPen);
        	
        MoveToEx(hdc, ptPrevious.x, ptPrevious.y, NULL); 
		
        LineTo(hdc, ptPrevious.x = LOWORD(lParam), 
          ptPrevious.y = HIWORD(lParam)); 
        ReleaseDC(hWnd, hdc); 
    } 
    return 0L; 
    
    
        case WM_CREATE: 
 
            // Get the metrics of the current font. 
 
            hdc = GetDC(hWnd); 
            GetTextMetrics(hdc, &tm); 
            ReleaseDC(hWnd, hdc); 
 
            // Save the average character width and height. 
 
            dwCharX = tm.tmAveCharWidth; 
            dwCharY = tm.tmHeight; 
 
            // Allocate a buffer to store keyboard input. 
 
            pchInputBuf = (LPTSTR) GlobalAlloc(GPTR, 
                BUFSIZE * sizeof(TCHAR)); 
            return 0; 
 
        case WM_SIZE: 
 
            // Save the new width and height of the client area. 
 
            dwClientX = LOWORD(lParam); 
            dwClientY = HIWORD(lParam); 
 
            // Calculate the maximum width of a line and the 
            // maximum number of lines in the client area. 
            
            dwLineLen = dwClientX - dwCharX; 
            dwLines = dwClientY / dwCharY; 
            break; 
            
             case WM_SETFOCUS: 
 
            // Create, position, and display the caret when the 
            // window receives the keyboard focus. 
 
            CreateCaret(hWnd, (HBITMAP) 1, 0, dwCharY); 
            SetCaretPos(nCaretPosX, nCaretPosY * dwCharY); 
            ShowCaret(hWnd); 
            break; 
            
            case WM_CHAR:
		// check if current location is close enough to the
		// end of the buffer that a buffer overflow may
		// occur. If so, add null and display contents. 
	if (cch > BUFSIZE-5)
	{
		pchInputBuf[cch] = 0x00;
		SendMessage(hWnd, WM_PAINT, 0, 0);
	} 
            switch (wParam) 
            { 
                case 0x08:  // backspace 
                case 0x0A:  // linefeed 
                case 0x1B:  // escape 
                    MessageBeep((UINT) -1); 
                    return 0; 
 
                case 0x09:  // tab 
 
                    // Convert tabs to four consecutive spaces. 
 
                    for (i = 0; i < 4; i++) 
                        SendMessage(hWnd, WM_CHAR, 0x20, 0); 
                    return 0; 
 
                case 0x0D:  // carriage return 
 
                    // Record the carriage return and position the 
                    // caret at the beginning of the new line.

                    pchInputBuf[cch++] = 0x0D; 
                    nCaretPosX = 0; 
                    nCaretPosY += 1; 
                    break; 
 
                default:    // displayable character 
 
                    ch = (TCHAR) wParam; 
                    HideCaret(hWnd); 
 
                    // Retrieve the character's width and output 
                    // the character. 
 
                    hdc = GetDC(hWnd); 
                    GetCharWidth32(hdc, (UINT) wParam, (UINT) wParam, 
                        &nCharWidth); 
                    TextOut(hdc, nCaretPosX, nCaretPosY * dwCharY, 
                        &ch, 1); 
                    ReleaseDC(hWnd, hdc); 
 
                    // Store the character in the buffer.
 
                    pchInputBuf[cch++] = ch; 
 
                    // Calculate the new horizontal position of the 
                    // caret. If the position exceeds the maximum, 
                    // insert a carriage return and move the caret 
                    // to the beginning of the next line. 
 
                    nCaretPosX += nCharWidth; 
                    if ((DWORD) nCaretPosX > dwLineLen) 
                    { 
                        nCaretPosX = 0;
                        pchInputBuf[cch++] = 0x0D; 
                        ++nCaretPosY; 
                    } 
                    nCurChar = cch; 
                    ShowCaret(hWnd); 
                    break; 
            } 
            SetCaretPos(nCaretPosX, nCaretPosY * dwCharY); 
            break; 
 
 
 
    case WM_KEYDOWN:
				switch(wParam)
				{
					case VK_LEFT:
				// Process the LEFT ARROW key.
				
				if(Index <4)
				{ 
					Index ++;
				}else
				{
					Index=0;
				}
				
				}
				break;
			default:


				
				return DefWindowProc(hWnd,message,wParam,lParam);
	}
	
	return 0;
	}
	

				
				
	



	


