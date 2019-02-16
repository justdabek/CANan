#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>
#include <QDebug>
#include <QDate>
#include <QHeaderView>
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
    ui->Trace->horizontalHeader()->setStretchLastSection(true);

    ui->MsgDef->setColumnWidth(0, 50);
    ui->MsgDef->setColumnWidth(1, 50);
    ui->MsgDef->setColumnWidth(2, 300);
    ui->MsgDef->setColumnWidth(3, 100);
    ui->MsgDef->setColumnWidth(4, 10);
    ui->MsgDef->setColumnWidth(5, 10);
    ui->MsgDef->horizontalHeader()->setStretchLastSection(true);

    QHeaderView *verticalHeader = ui->MsgDef->verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader->setDefaultSectionSize(24);

    verticalHeader = ui->Trace->verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader->setDefaultSectionSize(20);


    csvFile.setFileName("testCsv.csv");
    txtFile.setFileName("testTxt.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
	serial->close();
}

void MainWindow::serialReceived(){
    msg.append(serial->readLine());

    if(msg.endsWith(0x0A)){
        handleMessage(msg);
        //qDebug()<<msg.data();
        msg.clear();
    }
}

void MainWindow::on_Connect_clicked()
{
	serial->open(QIODevice::ReadWrite);
    connectTime.restart();
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

    int dlc = ui->MsgDef->item(rows[0].row(), 1)->text().toInt(&ok,16);
    int id = ui->MsgDef->item(rows[0].row(), 0)->text().toInt(&ok,16);
	if (!ok)
		return;

	QByteArray msg(dlc + 8, 0);
	if (!generateMessage(msg, id, dlc, ui->MsgDef->item(rows[0].row(), 2)->text()))
		return;
    serial->write(msg);

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

    if(ui->checkBox->isChecked()){
        if(ui->SingleFrameRadio->isChecked()){
            if(id!=singleFrameFiler) return;
        }else if(ui->RangeRadio->isChecked()){
            if((id<RangeFilterMin) || (id>RangeFilterMax)) return;
        }
    }

    double time=connectTime.elapsed();
	int row = ui->Trace->rowCount();
    ui->Trace->insertRow(row);
    ui->Trace->setItem(row, 0, new QTableWidgetItem( QString::number(time/1000)));
    ui->Trace->setItem(row, 1, new QTableWidgetItem(QString::number(id,16)));
	ui->Trace->setItem(row, 2, new QTableWidgetItem(QString(type)));
	ui->Trace->setItem(row, 3, new QTableWidgetItem(QString::number(dlc)));
	ui->Trace->setItem(row, 4, new QTableWidgetItem(data));

    if(ui->SaveToCsv->isChecked()){
        saveToCsv(row);
     }
    if(ui->SaveToTxt->isChecked()){
        saveToTxt(row);
     }


    ui->Trace->scrollToBottom();
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
    qDebug()<<msg;
	return true;
}

void MainWindow::saveToTxt(int row){
    QString textData;
    QTextStream out(&txtFile);
    int column = ui->Trace->columnCount();

    if(!txtFile.isOpen()){
        txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
        textData.append("Start logging: ");
        textData.append(QDateTime::currentDateTime().toString());
        textData+="\nTimeStamp\tID\t  Tx/Rx\t\tDLC\t     Data\t\n";
    }

    textData += ui->Trace->model()->data(ui->Trace->model()->index(row,0)).toString()+"\t\t";
    textData += ui->Trace->model()->data(ui->Trace->model()->index(row,1)).toString()+"\t\t";
    textData += ui->Trace->model()->data(ui->Trace->model()->index(row,2)).toString()+"\t\t";
    textData += ui->Trace->model()->data(ui->Trace->model()->index(row,3)).toString()+"\t\t";
    textData += ui->Trace->model()->data(ui->Trace->model()->index(row,4)).toString();
    //qDebug()<<textData;
    out << textData;
}

void MainWindow::saveToCsv(int row){
    QString textData;
    QTextStream out(&csvFile);
    int column = ui->Trace->columnCount();

    if(!csvFile.isOpen())
        csvFile.open(QIODevice::WriteOnly | QIODevice::Truncate);

    for (int j = 0; j < column; j++) {
            textData += ui->Trace->model()->data(ui->Trace->model()->index(row,j)).toString();
            textData += "; ";      // for .csv file format
    }
    textData += "\n";             // (optional: for new line segmentation)

    //qDebug()<<textData;
    out << textData;
}

void MainWindow::on_SaveToTxt_clicked(bool checked)
{
    if(!checked){
        txtFile.close();
    }
}


void MainWindow::on_SaveToCsv_clicked(bool checked)
{
    if(!checked){
        csvFile.close();
    }
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    bool ok;
    if(checked){
        if(ui->SingleFrameRadio->isChecked()){
            singleFrameFiler=ui->SingleFrameLine->text().toInt(&ok,16);
        }else{
            RangeFilterMin=ui->RangeMinLine->text().toInt(&ok,16);
            RangeFilterMax=ui->RangeMaxLine->text().toInt(&ok,16);
        }
    }
}
