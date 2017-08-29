#include <windows.h>

LONG WINAPI WndProc (HWND, UINT, WPARAM, LPARAM);

int     	WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
LPSTR lpszCmdLine, int nCmdShow)
{
WNDCLASS wc;
HWND hwnd;
MSG msg;
/***************** 1. Define Windows class ****************************/
wc.style = 0; // Class style
wc.lpfnWndProc = (WNDPROC) WndProc; // Window procedure address
wc.cbClsExtra = 0; // Class extra bytes
wc.cbWndExtra = 0; // Window extra bytes
wc.hInstance = hInstance; // Instance handle
wc.hIcon = LoadIcon (NULL, IDI_WINLOGO); // Icon handle
wc.hCursor = LoadCursor (NULL, IDC_ARROW); // Cursor handle
wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1); // Background color
wc.lpszMenuName = NULL; // Menu name
wc.lpszClassName = "MyWndClass"; // WNDCLASS name

/***************** 2. Register the Windows class **********************/

RegisterClass (&wc);

/***************** 3. Create window **********************/
hwnd = CreateWindow (
"MyWndClass", // WNDCLASS name
"SDK Application", // Window title
WS_OVERLAPPEDWINDOW, // Window style
CW_USEDEFAULT, // Horizontal position
CW_USEDEFAULT, // Vertical position
CW_USEDEFAULT, // Initial width
CW_USEDEFAULT, // Initial height
HWND_DESKTOP, // Handle of parent window
NULL, // Menu handle
hInstance, // Application's instance handle
NULL // Window-creation data
);

/***************** 4. Display the window **********************/
ShowWindow (hwnd, nCmdShow);
UpdateWindow (hwnd);

/***************** 5. Message loop **********************/
while (GetMessage (&msg, NULL, 0, 0)) {
TranslateMessage (&msg);
DispatchMessage (&msg);
}
return msg.wParam;
}






LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam,
LPARAM lParam)
{
PAINTSTRUCT ps;
HDC hdc;

switch (message) {

case WM_PAINT:
hdc = BeginPaint (hwnd, &ps);


SelectObject(hdc,CreatePen(PS_SOLID,2,RGB(0,0,0)));
SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));

Ellipse	(hdc,200-200,240,317-200,275);
Ellipse	(hdc,320-200,240,410-200,275);


Rectangle(hdc,260-200,340,300-200,380); //L LEG
Rectangle(hdc,310-200,340,350-200,380); //R LEG
Ellipse(hdc,240-200,210,370-200,360); // Bo


SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse(hdc,260-200,240,350-200,340); // Bi

SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
Ellipse (hdc,230-200,100,380-200,260); // Crocket

SelectObject(hdc,CreateSolidBrush(RGB(255,255,0)));
Ellipse	(hdc,288-200,250,317-200,275); // Bell

SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));
Ellipse (hdc,210-200,60,400-200,250);	//FO

SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse (hdc,220-200,100,390-200,250); //FI
Ellipse(hdc,250-200,80,300-200,150); // Leye
Ellipse(hdc,300-200,80,350-200,150); //Reye
SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
Ellipse(hdc,285-200,137,315-200,167);// nose

Ellipse(hdc,300-200,167,301-200,210);// Line Nose
SetArcDirection(hdc, AD_COUNTERCLOCKWISE);
Arc(hdc, 240-200, 100, 365-200, 210, 200-200, 208, 480-200,220);


Arc(hdc, 275-200, 270, 335-200, 325,10, 300, 480-200,300 );

Arc(hdc, 275-200, 120, 300-200, 125,275-200, 125 ,300-200,125 );
Arc(hdc, 300-200, 120, 325-200, 125,300-200, 125 ,325-200,125 );
MoveToEx(hdc,275-200,295,NULL);
LineTo(hdc,335-200,295);

SelectObject(hdc,CreatePen(PS_SOLID,1,RGB(30,144,255)));
SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));
Rectangle(hdc,262-200,340,298-200,370); // Color LLeg
Rectangle(hdc,312-200,340,348-200,370); // Color LLeg
SelectObject(hdc,CreatePen(PS_SOLID,2,RGB(0,0,0)));
SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse(hdc,250-200,370,304-200,395); //L F
Ellipse(hdc,305-200,370,358-200,395); //R F



Ellipse	(hdc,180-200,240,215-200,275);





Ellipse	(hdc,390-200,240,425-200,275);

MoveToEx(hdc,223-200,140,NULL);
LineTo(hdc,275-200,160);   //L Bread 1
MoveToEx(hdc,223-200,170,NULL);
LineTo(hdc,275-200,173);  //L Bread 2

MoveToEx(hdc,223-200,193,NULL);
LineTo(hdc,275-200,183);  // L Bread 3



MoveToEx(hdc,325-200,160,NULL);
LineTo(hdc,385-200,140);   //R Bread 1
MoveToEx(hdc,325-200,170,NULL);
LineTo(hdc,385-200,168);  //R Bread 2
MoveToEx(hdc,325-200,183,NULL);
LineTo(hdc,385-200,193);  // L Bread 3


// Two


SelectObject(hdc,CreatePen(PS_SOLID,2,RGB(0,0,0)));
SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));

Ellipse	(hdc,200,240,317,275);
Ellipse	(hdc,320,240,410,275);


Rectangle(hdc,260,340,300,380); //L LEG
Rectangle(hdc,310,340,350,380); //R LEG
Ellipse(hdc,240,210,370,360); // Bo


SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse(hdc,260,240,350,340); // Bi

SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
Ellipse (hdc,230,100,380,260); // Crocket

SelectObject(hdc,CreateSolidBrush(RGB(255,255,0)));
Ellipse	(hdc,288,250,317,275); // Bell

SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));
Ellipse (hdc,210,60,400,250);	//FO

SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse (hdc,220,100,390,250); //FI
Ellipse(hdc,250,80,300,150); // Leye
Ellipse(hdc,300,80,350,150); //Reye
SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
Ellipse(hdc,285,137,315,167);// nose

Ellipse(hdc,300,167,301,210);// Line Nose
SetArcDirection(hdc, AD_COUNTERCLOCKWISE);
Arc(hdc, 240, 100, 365, 210, 200, 208, 480,220 );


Arc(hdc, 275, 270, 335, 325,10, 300, 480,300 );

Arc(hdc, 275, 120, 300, 125,275, 125 ,300,125 );
Arc(hdc, 300, 120, 325, 125,300, 125 ,325,125 );
MoveToEx(hdc,275,295,NULL);
LineTo(hdc,335,295);

SelectObject(hdc,CreatePen(PS_SOLID,1,RGB(30,144,255)));
SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));
Rectangle(hdc,262,340,298,370); // Color LLeg
Rectangle(hdc,312,340,348,370); // Color LLeg
SelectObject(hdc,CreatePen(PS_SOLID,2,RGB(0,0,0)));
SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse(hdc,250,370,304,395); //L F
Ellipse(hdc,305,370,358,395); //R F



Ellipse	(hdc,180,240,215,275);





Ellipse	(hdc,390,240,425,275);

MoveToEx(hdc,223,140,NULL);
LineTo(hdc,275,160);   //L Bread 1
MoveToEx(hdc,223,170,NULL);
LineTo(hdc,275,173);  //L Bread 2

MoveToEx(hdc,223,193,NULL);
LineTo(hdc,275,183);  // L Bread 3



MoveToEx(hdc,325,160,NULL);
LineTo(hdc,385,140);   //R Bread 1
MoveToEx(hdc,325,170,NULL);
LineTo(hdc,385,168);  //R Bread 2
MoveToEx(hdc,325,183,NULL);
LineTo(hdc,385,193);  // L Bread 3




// three



SelectObject(hdc,CreatePen(PS_SOLID,2,RGB(0,0,0)));
SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));

Ellipse	(hdc,200+200,240,317+200,275);
Ellipse	(hdc,320+200,240,410+200,275);


Rectangle(hdc,260+200,340,300+200,380); //L LEG
Rectangle(hdc,310+200,340,350+200,380); //R LEG
Ellipse(hdc,240+200,210,370+200,360); // Bo


SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse(hdc,260+200,240,350+200,340); // Bi

SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
Ellipse (hdc,230+200,100,380+200,260); // Crocket

SelectObject(hdc,CreateSolidBrush(RGB(255,255,0)));
Ellipse	(hdc,288+200,250,317+200,275); // Bell

SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));
Ellipse (hdc,210+200,60,400+200,250);	//FO

SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse (hdc,220+200,100,390+200,250); //FI
Ellipse(hdc,250+200,80,300+200,150); // Leye
Ellipse(hdc,300+200,80,350+200,150); //Reye
SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
Ellipse(hdc,285+200,137,315+200,167);// nose

Ellipse(hdc,300+200,167,301+200,210);// Line Nose
SetArcDirection(hdc, AD_COUNTERCLOCKWISE);
Arc(hdc, 240+200, 100, 365+200, 210, 200+200, 208, 480+200,220 );


Arc(hdc, 275+200, 270, 335+200, 325,10+200, 300, 480+200,300 );

Arc(hdc, 275+200, 120, 300+200, 125,275+200, 125 ,300+200,125 );
Arc(hdc, 300+200, 120, 325+200, 125,300+200, 125 ,325+200,125 );
MoveToEx(hdc,275+200,295,NULL);
LineTo(hdc,335+200,295);

SelectObject(hdc,CreatePen(PS_SOLID,1,RGB(30,144,255)));
SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));
Rectangle(hdc,262+200,340,298+200,370); // Color LLeg
Rectangle(hdc,312+200,340,348+200,370); // Color LLeg
SelectObject(hdc,CreatePen(PS_SOLID,2,RGB(0,0,0)));
SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse(hdc,250+200,370,304+200,395); //L F
Ellipse(hdc,305+200,370,358+200,395); //R F



Ellipse	(hdc,180+200,240,215+200,275);





Ellipse	(hdc,390+200,240,425+200,275);

MoveToEx(hdc,223+200,140,NULL);
LineTo(hdc,275+200,160);   //L Bread 1
MoveToEx(hdc,223+200,170,NULL);
LineTo(hdc,275+200,173);  //L Bread 2

MoveToEx(hdc,223+200,193,NULL);
LineTo(hdc,275+200,183);  // L Bread 3



MoveToEx(hdc,325+200,160,NULL);
LineTo(hdc,385+200,140);   //R Bread 1
MoveToEx(hdc,325+200,170,NULL);
LineTo(hdc,385+200,168);  //R Bread 2
MoveToEx(hdc,325+200,183,NULL);
LineTo(hdc,385+200,193);  // L Bread 3


// Four

SelectObject(hdc,CreatePen(PS_SOLID,2,RGB(0,0,0)));
SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));

Ellipse	(hdc,200+400,240,317+400,275);
Ellipse	(hdc,320+400,240,410+400,275);


Rectangle(hdc,260+400,340,300+400,380); //L LEG
Rectangle(hdc,310+400,340,350+400,380); //R LEG
Ellipse(hdc,240+400,210,370+400,360); // Bo


SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse(hdc,260+400,240,350+400,340); // Bi

SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
Ellipse (hdc,230+400,100,380+400,260); // Crocket

SelectObject(hdc,CreateSolidBrush(RGB(255,255,0)));
Ellipse	(hdc,288+400,250,317+400,275); // Bell

SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));
Ellipse (hdc,210+400,60,400+400,250);	//FO

SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse (hdc,220+400,100,390+400,250); //FI
Ellipse(hdc,250+400,80,300+400,150); // Leye
Ellipse(hdc,300+400,80,350+400,150); //Reye
SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
Ellipse(hdc,285+400,137,315+400,167);// nose

Ellipse(hdc,300+400,167,301+400,210);// Line Nose
SetArcDirection(hdc, AD_COUNTERCLOCKWISE);
Arc(hdc, 240+400, 100, 365+400, 210, 200+400, 208, 480+400,220 );


Arc(hdc, 275+400, 270, 335+400, 325,10+400, 300, 480+400,300 );

Arc(hdc, 275+400, 120, 300+400, 125,275+400, 125 ,300+400,125 );
Arc(hdc, 300+400, 120, 325+400, 125,300+400, 125 ,325+400,125 );
MoveToEx(hdc,275+400,295,NULL);
LineTo(hdc,335+400,295);

SelectObject(hdc,CreatePen(PS_SOLID,1,RGB(30,144,255)));
SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));
Rectangle(hdc,262+400,340,298+400,370); // Color LLeg
Rectangle(hdc,312+400,340,348+400,370); // Color LLeg
SelectObject(hdc,CreatePen(PS_SOLID,2,RGB(0,0,0)));
SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse(hdc,250+400,370,304+400,395); //L F
Ellipse(hdc,305+400,370,358+400,395); //R F



Ellipse	(hdc,180+400,240,215+400,275);





Ellipse	(hdc,390+400,240,425+400,275);

MoveToEx(hdc,223+400,140,NULL);
LineTo(hdc,275+400,160);   //L Bread 1
MoveToEx(hdc,223+400,170,NULL);
LineTo(hdc,275+400,173);  //L Bread 2

MoveToEx(hdc,223+400,193,NULL);
LineTo(hdc,275+400,183);  // L Bread 3



MoveToEx(hdc,325+400,160,NULL);
LineTo(hdc,385+400,140);   //R Bread 1
MoveToEx(hdc,325+400,170,NULL);
LineTo(hdc,385+400,168);  //R Bread 2
MoveToEx(hdc,325+400,183,NULL);
LineTo(hdc,385+400,193);  // L Bread 3



// FIVE

SelectObject(hdc,CreatePen(PS_SOLID,2,RGB(0,0,0)));
SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));

Ellipse	(hdc,200+600,240,317+600,275);
Ellipse	(hdc,320+600,240,410+600,275);


Rectangle(hdc,260+600,340,300+600,380); //L LEG
Rectangle(hdc,310+600,340,350+600,380); //R LEG
Ellipse(hdc,240+600,210,370+600,360); // Bo


SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse(hdc,260+600,240,350+600,340); // Bi

SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
Ellipse (hdc,230+600,100,380+600,260); // Crocket

SelectObject(hdc,CreateSolidBrush(RGB(255,255,0)));
Ellipse	(hdc,288+600,250,317+600,275); // Bell

SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));
Ellipse (hdc,210+600,60,400+600,250);	//FO

SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse (hdc,220+600,100,390+600,250); //FI
Ellipse(hdc,250+600,80,300+600,150); // Leye
Ellipse(hdc,300+600,80,350+600,150); //Reye
SelectObject(hdc,CreateSolidBrush(RGB(255,0,0)));
Ellipse(hdc,285+600,137,315+600,167);// nose

Ellipse(hdc,300+600,167,301+600,210);// Line Nose
SetArcDirection(hdc, AD_COUNTERCLOCKWISE);
Arc(hdc, 240+600, 100, 365+600, 210, 200+600, 208, 480+600,220 );


Arc(hdc, 275+600, 270, 335+600, 325,10+600, 300, 480+600,300 );

Arc(hdc, 275+600, 120, 300+600, 125,275+600, 125 ,300+600,125 );
Arc(hdc, 300+600, 120, 325+600, 125,300+600, 125 ,325+600,125 );
MoveToEx(hdc,275+600,295,NULL);
LineTo(hdc,335+600,295);

SelectObject(hdc,CreatePen(PS_SOLID,1,RGB(30,144,255)));
SelectObject(hdc,CreateSolidBrush(RGB(30,144,255)));
Rectangle(hdc,262+600,340,298+600,370); // Color LLeg
Rectangle(hdc,312+600,340,348+600,370); // Color LLeg
SelectObject(hdc,CreatePen(PS_SOLID,2,RGB(0,0,0)));
SelectObject(hdc,CreateSolidBrush(RGB(255,255,255)));
Ellipse(hdc,250+600,370,304+600,395); //L F
Ellipse(hdc,305+600,370,358+600,395); //R F



Ellipse	(hdc,180+600,240,215+600,275);





Ellipse	(hdc,390+600,240,425+600,275);

MoveToEx(hdc,223+600,140,NULL);
LineTo(hdc,275+600,160);   //L Bread 1
MoveToEx(hdc,223+600,170,NULL);
LineTo(hdc,275+600,173);  //L Bread 2

MoveToEx(hdc,223+600,193,NULL);
LineTo(hdc,275+600,183);  // L Bread 3



MoveToEx(hdc,325+600,160,NULL);
LineTo(hdc,385+600,140);   //R Bread 1
MoveToEx(hdc,325+600,170,NULL);
LineTo(hdc,385+600,168);  //R Bread 2
MoveToEx(hdc,325+600,183,NULL);
LineTo(hdc,385+600,193);  // L Bread 3


EndPaint (hwnd, &ps);
return 0;

case WM_DESTROY:
PostQuitMessage (0);
return 0;
}
return DefWindowProc (hwnd, message, wParam, lParam);
}

