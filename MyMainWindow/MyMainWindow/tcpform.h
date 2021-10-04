#ifndef TCPFORM_H
#define TCPFORM_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>
namespace Ui {
class TcpForm;
}

class TcpForm : public QWidget {
  Q_OBJECT

 public:
  explicit TcpForm(QWidget *parent = nullptr);
  ~TcpForm();

 private slots:
  void sendMessage();

 private:
  Ui::TcpForm *ui;
  QTcpServer *tcpServer;
};

#endif  // TCPFORM_H
