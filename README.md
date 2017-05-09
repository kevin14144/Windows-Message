# Windows Message
 

###程序間通訊
透過Window message機制讓視窗、程式之間能夠溝通、傳遞資料。

###測試環境:
Window 7、QT 5.7

###流程動作
A程式透過Window message發送資料給B程式

###Windows API 方法
* 資源
Include <Windows.h>   
Library: User32.lib   
DLL: User32.dll   

* 功能: 查找視窗
HWND WINAPI FindWindow(
  _In_opt_ LPCTSTR lpClassName,
  _In_opt_ LPCTSTR lpWindowName
);

lpClassName :    
視窗類別名稱，基本上使用NULL即是查找視窗標題符合lpWindowName的視窗。

lpWindowName:     
視窗標題名稱。
Return:    
回傳視窗handle(句柄)

* 功能: 傳送視窗訊息
LRESULT WINAPI SendMessage(    
  _In_ HWND   hWnd,    
  _In_ UINT   Msg,    
  _In_ WPARAM wParam,    
  _In_ LPARAM lParam   
);   

hWnd :   
接收訊息的視窗handle(句柄)(從FindWindows得到)，或可以指定為系統上所有上層視窗(HWND_BROADCAST)    

Msg:    
傳送的訊息種類(eg: WM_COPYDATA)   
wParam:    
傳送的訊息    
lParam:   
傳送的訊息   
Return:    
回傳訊息處理結果   

* 功能: 傳送資料結構 (當使用訊息種類WM_COPYDATA)

typedef struct tagCOPYDATASTRUCT {   
  ULONG_PTR dwData;   
  DWORD     cbData;   
  PVOID     lpData;   
} COPYDATASTRUCT, *PCOPYDATASTRUCT;    

dwData:   
傳遞資料(可用來分類訊息)    
cbData:    
lpDat:    
資料大小(sizeof)   
lpData:    
傳遞到接收端的資料指標   


