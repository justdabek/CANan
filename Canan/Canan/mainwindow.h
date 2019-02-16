#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void serialReceived();
    void on_Connect_clicked();
    void on_Clear_released();
    void on_pushButton_released();
	void on_send_released();

	void on_receive_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray buffer;
    QByteArray MsgBuffer;

	void handleMessage(QByteArray const& msg);
	bool generateMessage(QByteArray& msg, int id, int dlc, QString const& text);
	QByteArray genMsg();
	void dbgMsg(QByteArray const& msg);
};

#endif // MAINWINDOW_H
