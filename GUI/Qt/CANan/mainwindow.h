#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QFile>

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

    //void on_receive_clicked();

    void on_SaveToTxt_clicked(bool checked);

    void on_SaveToCsv_clicked(bool checked);
    void on_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QByteArray buffer;
    QByteArray MsgBuffer;
    QByteArray msg;
    QTime connectTime;
    int singleFrameFiler;
    int RangeFilterMin;
    int RangeFilterMax;

	QByteArray genMsg();
	void dbgMsg(QByteArray const& msg);
    void saveToTxt(int row);
    void saveToCsv(int row);
    void handleMessage(QByteArray const& msg);
    bool generateMessage(QByteArray& msg, int id, int dlc, QString const& text);
    QFile csvFile;
    QFile txtFile;
};

#endif // MAINWINDOW_H
