#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->leWindowTitle->setText("Mainwindow");
    ui->leTargeWindowTitle->setText("Mainwindow");
}


MainWindow::~MainWindow()
{
    delete ui;
}

//const ULONG_PTR Condition_type = 0.0;//To redefine the message.
enum Condition_type
{
    ShowSenderID = 0,
    ShowMessage
};

void MainWindow::on_btnSetWindowTitle_clicked()
{
    setWindowTitle(ui->leWindowTitle->text());
}

void MainWindow::on_btnSendMessage_clicked()
{
    SendWindowMsg();
}


void MainWindow::SendWindowMsg()
{
    //FindWindow
    LPWSTR windowName = (LPWSTR)ui->leTargeWindowTitle->text().utf16();
    HWND hwnd = ::FindWindow(NULL, windowName);//L Long, (LPWSTR)L"Mainwindow"

    //Build Message
    QString sendText = ui->leSendText->text();
    QByteArray data = sendText.toUtf8();
    COPYDATASTRUCT copyData;
    copyData.dwData = ui->sbMessageType->value();//Data 1, We can use this value to check which condition it will be processing.
    copyData.cbData = data.size();//Data 2 Size(byte)
    copyData.lpData = data.data();//Data 2 (Point)

    if (::IsWindow(hwnd))
    {
        HWND sender = (HWND)effectiveWinId();
        //QString to Char*
        QByteArray windowTitleTemp = this->windowTitle().toLatin1();
        char* windowTitleTempPoint = windowTitleTemp.data();
        qDebug()<<sender;
        ::SendMessage(hwnd, WM_COPYDATA, reinterpret_cast<WPARAM>(windowTitleTempPoint),(LPARAM)&copyData );
    }
    else
    {
        ui->lbShowMessage->setText("Didn't find the traget window!");
        qDebug() <<"Didn't find the traget window!";
    }

}


bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG *param = static_cast<MSG *>(message);
    COPYDATASTRUCT *cds = 0;
    QString strMessage;

    switch (param->message)
    {
    case WM_COPYDATA:
        cds = (COPYDATASTRUCT*)(param->lParam);
        strMessage = QString::fromUtf8((char*)(cds->lpData),cds->cbData);

        switch(cds->dwData)
        {
        case Condition_type::ShowSenderID:
            ui->lbShowMessage->setText((QString)((char*)param->wParam));
            break;
        case Condition_type::ShowMessage:
            ui->lbShowMessage->setText(strMessage);
            break;
        default:
            qDebug() <<"notihing to do.";
            break;
        }
        return true;
        break;

    default:

        break;
    }

    return QWidget::nativeEvent(eventType, message, result);
}

