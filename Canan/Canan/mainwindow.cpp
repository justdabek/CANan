#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QSerialPort>
//#include <QSerialPortInfo>
#include <QThread>
#include <QDebug>
#include <QDate>
QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	serial = new QSerialPort(this);
	serial->setPortName("COM3");
	serial->setBaudRate(QSerialPort::Baud115200);
	serial->setDataBits(QSerialPort::Data8);
	serial->setParity(QSerialPort::NoParity);
	serial->setStopBits(QSerialPort::OneStop);
	serial->setFlowControl(QSerialPort::NoFlowControl);
	ui->Trace->setColumnWidth(0, 100);
	ui->Trace->setColumnWidth(1, 50);
	ui->Trace->setColumnWidth(2, 50);
	ui->Trace->setColumnWidth(3, 50);
	ui->Trace->setColumnWidth(4, 410);
	ui->MsgDef->setColumnWidth(0, 50);
	ui->MsgDef->setColumnWidth(1, 50);
	ui->MsgDef->setColumnWidth(2, 545);
}

MainWindow::~MainWindow()
{
    delete ui;
	serial->close();
}

void MainWindow::serialReceived(){
	QByteArray msg;
	msg=serial->readLine();
	handleMessage(msg);
}

void MainWindow::on_Connect_clicked()
{
	serial->open(QIODevice::ReadWrite);
	connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));
}

void MainWindow::on_Clear_released()
{
    buffer.clear();
	ui->Trace->clearContents();
	ui->Trace->setRowCount(0);
}

void MainWindow::on_pushButton_released()
{
	serial->close();
}

void MainWindow::on_send_released()
{
	bool ok;
	QItemSelectionModel* model = ui->MsgDef->selectionModel();
	QModelIndexList rows = model->selectedRows();
	if (rows.empty())
		return;

	int dlc = ui->MsgDef->item(rows[0].row(), 1)->text().toInt(&ok);
	int id = ui->MsgDef->item(rows[0].row(), 0)->text().toInt(&ok);
	if (!ok)
		return;

	QByteArray msg(dlc + 8, 0);
	if (!generateMessage(msg, id, dlc, ui->MsgDef->item(rows[0].row(), 2)->text()))
		return;
	serial->write(Msg);

}


void MainWindow::handleMessage(const QByteArray &msg)
{
	const char* msgdata = msg.data();
	char type;
	uint32_t id;
	uint32_t dlc;
	uint nread;
	sscanf(msgdata, "%c %x %x%n", &type, &id, &dlc, &nread);
	QString data = msgdata + nread;

	QTime time = QTime::currentTime();
	int row = ui->Trace->rowCount();
	ui->Trace->insertRow(row);
	ui->Trace->setItem(row, 0, new QTableWidgetItem( QTime::currentTime().toString("hh:mm:ss.zzz")));
	ui->Trace->setItem(row, 1, new QTableWidgetItem(QString::number(id)));
	ui->Trace->setItem(row, 2, new QTableWidgetItem(QString(type)));
	ui->Trace->setItem(row, 3, new QTableWidgetItem(QString::number(dlc)));
	ui->Trace->setItem(row, 4, new QTableWidgetItem(data));
}

bool MainWindow::generateMessage(QByteArray &msg, int id, int dlc, const QString& text)
{
	bool ok;
	int im = 0;
	uint8_t* pid = (uint8_t*)&id;
	uint8_t* pdlc = (uint8_t*)&dlc;
	for (uint8_t* p = pid + 3; p >= pid; --p)
		msg[im++] = *p;
	for (uint8_t* p = pdlc + 3; p >= pdlc; --p)
		msg[im++] = *p;

	QStringList parts = text.split(QRegularExpression("\\s+"));
	if (parts.size() > dlc)
		return false;

	for (QString s : parts){		
		msg[im++] = s.toUInt(&ok, 16);
		if (!ok)
			return false;
	}
	return true;
}

