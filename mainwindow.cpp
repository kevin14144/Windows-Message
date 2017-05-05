#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdlib.h"

//#ifdef Q_OS_WIN
//#pragma comment(lib, "user32.lib")
//#include <qt_windows.h>
//#endif
#include "Windows.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{

    delete ui;
}

const QString c_strTitle = "Mainwindow";
void MainWindow::TesWindowMsg()
{

    //   LPWSTR path = (LPWSTR)c_strTitle.unicode();  //path = L"SendMessage"
    //   HWND hwnd =  FindWindow(NULL,path);
    //   SendMessage(hwnd,WM_COPYDATA,(WPARAM)1,(LPARAM)123);

    HWND hwnd = NULL;

    LPWSTR path = (LPWSTR)c_strTitle.utf16();  //path = L"SendMessage"
    hwnd = ::FindWindowW(NULL, path);

    QString filename = ui->lineEdit->text();//QStringLiteral("进程通信-Windows消息");
    QByteArray data = filename.toUtf8();

    COPYDATASTRUCT b;
    b.dwData =0;
    b.cbData =data.size();
    b.lpData = data.data();

    if (::IsWindow(hwnd))
    {

        HWND sender = (HWND)effectiveWinId();
//        ::SendMessage(hwnd, WM_COPYDATA, reinterpret_cast<WPARAM>(sender),(LPARAM)&b );
        ::SendMessage(hwnd, WM_COPYDATA, reinterpret_cast<WPARAM>(sender),(LPARAM)"A" );
    }




}



void MainWindow::on_pushButton_clicked()
{
    TesWindowMsg();
}


bool  MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG *param = static_cast<MSG *>(message);

    switch (param->message)
    {
    case WM_COPYDATA:
        COPYDATASTRUCT *cds = reinterpret_cast<COPYDATASTRUCT*>(param->lParam);
        //QString strMessage = QString::fromUtf8(reinterpret_cast<char*>(cds->lpData), cds->cbData);
//        QString strMessage = QString::fromUtf8(reinterpret_cast<char*>(cds->lpData), cds->cbData);


        char* f = (char*)param->lParam;
        ui->lineEdit->setText(f);
        return true;


        break;
    }

    return QWidget::nativeEvent(eventType, message, result);
}
