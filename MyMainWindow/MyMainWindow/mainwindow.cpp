#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  qDebug() << "QSslSocket=" << QSslSocket::sslLibraryBuildVersionString();
  qDebug() << "OpenSSL支持情况:" << QSslSocket::supportsSsl();

  // 下载文件
  manager = new QNetworkAccessManager(this);
  ui->progressBar->hide();

  // 获取网络接口信息
  QString localHostName = QHostInfo::localHostName();
  QHostInfo info = QHostInfo::fromName(localHostName);
  qDebug() << "localHostName: " << localHostName << endl
           << "IP Address: " << info.addresses();

  QHostInfo::lookupHost("ljq.aly.q-q.online", this, SLOT(loopedUp(QHostInfo)));

  // 获取所有网络接口列表
  QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
  foreach (QNetworkInterface interface, list) {
    qDebug() << "接口名称: " << interface.name();
    qDebug() << "硬件地址: " << interface.hardwareAddress();
    // 获取IP地址条目列表，每个条目包含一个IP地址、子网掩码和广播地址
    QList<QNetworkAddressEntry> entryList = interface.addressEntries();
    foreach (QNetworkAddressEntry entry, entryList) {
      qDebug() << "IP地址: " << entry.ip().toString();
      qDebug() << "子网掩码:" << entry.netmask().toString();
      qDebug() << "广播地址: " << entry.broadcast().toString();
    }
    qDebug();
  }

  // DNS查询
  dns = new QDnsLookup(this);
  connect(dns, SIGNAL(finished()), this, SLOT(handleServers()));
  dns->setType(QDnsLookup::SRV);
  dns->setName("_xmpp-client._tcp.gmail.com");
  dns->lookup();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::startRequest(QUrl url) {
  reply = manager->get(QNetworkRequest(url));
  connect(reply, &QNetworkReply::readyRead, this, &MainWindow::httpReadyRead);
  connect(reply, &QNetworkReply::downloadProgress, this,
          &MainWindow::updateDataReadProgress);
  connect(reply, &QNetworkReply::finished, this, &MainWindow::httpFinished);
}

void MainWindow::httpFinished() {
  ui->progressBar->hide();
  if (file) {
    file->close();
    delete file;
    file = nullptr;
  }
  reply->deleteLater();
  reply = nullptr;
}

void MainWindow::httpReadyRead() {
  if (file) file->write(reply->readAll());
}

void MainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes) {
  ui->progressBar->setMaximum(totalBytes);
  ui->progressBar->setValue(bytesRead);
}

void MainWindow::on_pushButton_clicked() {
  //  url = ui->lineEdit->text();
  url.setScheme("sftp");
  url.setHost("ljq.aly.q-q.online");
  url.setPath("web.war");
  url.setUserName("q");
  url.setPassword("200076");
  QFileInfo info(url.path());
  QString fileName(info.fileName());
  if (fileName.isEmpty()) fileName = "index.html";
  qDebug() << fileName;
  file = new QFile(fileName);
  if (!file->open(QIODevice::WriteOnly)) {
    delete file;
    file = nullptr;
    return;
  }
  startRequest(url);
  ui->progressBar->setValue(0);
  ui->progressBar->show();
}

void MainWindow::loopedUp(const QHostInfo &host) {
  if (host.error() != QHostInfo::NoError) {
    qDebug() << "Loopup failed:" << host.errorString();
    return;
  }
  foreach (const QHostAddress &address, host.addresses()) {
    qDebug() << "Found address:" << address.toString();
  }
  qDebug() << "Found hostName:" << host.hostName();
}

void MainWindow::handleServers() {
  if (dns->error() != QDnsLookup::NoError) {
    qWarning("DNS lookup failed");
    dns->deleteLater();
    return;
  }
  foreach (const QDnsServiceRecord &record, dns->serviceRecords()) {
    // 处理结果
    qDebug() << record.target();
  }
  dns->deleteLater();
}
