#include "tcpform.h"

#include "ui_tcpform.h"

TcpForm::TcpForm(QWidget *parent) : QWidget(parent), ui(new Ui::TcpForm) {
  ui->setupUi(this);
  tcpServer = new QTcpServer(this);
  // 使用IPV4本地主机地址，等价于QHostAddress("127.0.0.1")
  if (!tcpServer->listen(QHostAddress::LocalHost, 12345)) {
    qDebug() << tcpServer->errorString();
    close();
  }
  connect(tcpServer, &QTcpServer::newConnection, this, &TcpForm::sendMessage);
}

TcpForm::~TcpForm() { delete ui; }

void TcpForm::sendMessage() {
  // 用于暂存要发送的数据
  QByteArray block;
  QDataStream out(&block, QIODevice::WriteOnly);
  // 设置数据流的版本，客户端和服务端使用的版本要相同
  out.setVersion(QDataStream::Qt_5_15);
  out << (quint16)0;
  out << tr("hello TCP !!!");
  out.device()->seek(0);
  out << (quint16)(block.size() - sizeof(quint16));
  // 获取已经建立连接的套接字
  QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
  connect(clientConnection, &QTcpSocket::disconnected, clientConnection,
          &QTcpSocket::deleteLater);
  clientConnection->write(block);
  clientConnection->disconnectFromHost();
  // 数据发送成功后，显示提示
  ui->textBrowser->append(tr("已发送") +
                          clientConnection->localAddress().toString());
}
