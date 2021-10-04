#include "udpform.h"

#include "ui_udpform.h"

UdpForm::UdpForm(QWidget *parent) : QWidget(parent), ui(new Ui::UdpForm) {
  ui->setupUi(this);
  sender = new QUdpSocket(this);
  receiver = new QUdpSocket(this);
  receiver->bind(12345, QUdpSocket::ShareAddress);
  connect(receiver, &QUdpSocket::readyRead, this,
          &UdpForm::processPendingDatagram);
}

UdpForm::~UdpForm() { delete ui; }

void UdpForm::on_pushButton_clicked() {
  static int i = 0;
    QByteArray datagram = "hello udp! " + QByteArray::number(i++);
  //  QHostAddress server;
  //  server.setAddress("127.0.0.1");
  sender->writeDatagram(datagram.data(), datagram.size(),
                        QHostAddress::Broadcast, 12345);
  qDebug() << "send over";
}

void UdpForm::processPendingDatagram() {
  while (receiver->hasPendingDatagrams()) {
    QByteArray datagram;
    // 让datagram的大小为等待处理的数据报的大小，这样才能接收到完整的数据
    datagram.resize(receiver->pendingDatagramSize());
    receiver->readDatagram(datagram.data(), datagram.size());
    ui->textBrowser->append(datagram);
  }
}
