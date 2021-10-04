#include <QApplication>
#include <QDebug>

#include "mainwindow.h"
#include "udpform.h"
#include "tcpform.h"
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
//  MainWindow w;
//  w.show();
//  UdpForm udp;
//  udp.show();
  TcpForm tcp;
  tcp.show();
  return a.exec();
}
