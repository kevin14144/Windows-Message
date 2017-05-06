#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Windows.h"
#include "QDebug"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    //Receive Window message event
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private slots:
    void on_btnSetWindowTitle_clicked();
    void on_btnSendMessage_clicked();

private:
    Ui::MainWindow *ui;
    //Send window message (WM_COPYDATA)
    void SendWindowMsg();




};

#endif // MAINWINDOW_H
