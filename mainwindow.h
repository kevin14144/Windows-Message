#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <Header.h>

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
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);//Receive Window message event

private slots:
    void on_btnSetWindowTitle_clicked();
    void on_btnSendMessage_clicked();

private:
    Ui::MainWindow *ui;
    void SendWindowMsg();
};

#endif // MAINWINDOW_H
