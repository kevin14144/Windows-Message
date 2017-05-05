#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Windows.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->leWindowTitle->setText("Mainwindow");
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SendWindowMsg()
{
    //FindWindow
    LPWSTR windowName = (LPWSTR)ui->leWindowTitle->text().utf16();
    HWND hwnd = ::FindWindow(NULL, windowName);//L Long

    //Message
    QString sendText = ui->leSendText->text();
    QByteArray data = sendText.toUtf8();
    COPYDATASTRUCT copyData;
    copyData.dwData = 0;//Data 1
    copyData.cbData = data.size();//Data 2 Size(byte)
    copyData.lpData = data.data();//Data 2 (Point)

    if (::IsWindow(hwnd))
    {
        HWND sender = (HWND)effectiveWinId();
        ::SendMessage(hwnd, WM_COPYDATA, reinterpret_cast<WPARAM>(sender),(LPARAM)&copyData );
    }

}



bool  MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG *param = static_cast<MSG *>(message);

    switch (param->message)
    {
    case WM_COPYDATA:
//        COPYDATASTRUCT *cds = reinterpret_cast<COPYDATASTRUCT*>(param->lParam);
        COPYDATASTRUCT *cds = (COPYDATASTRUCT*)(param->lParam);
//        QString strMessage = QString::fromUtf8(reinterpret_cast<char*>(cds->lpData), cds->cbData);
        QString strMessage = (char*)(cds->lpData);
        ui->lbShowMessage->setText(strMessage);
        return true;
        break;
    }

    return QWidget::nativeEvent(eventType, message, result);
}


void MainWindow::on_btnSetWindowTitle_clicked()
{
    setWindowTitle(ui->leWindowTitle->text());
}

void MainWindow::on_btnSendMessage_clicked()
{
    SendWindowMsg();
}
