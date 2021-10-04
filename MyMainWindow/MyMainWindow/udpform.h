#ifndef UDPFORM_H
#define UDPFORM_H

#include <QUdpSocket>
#include <QWidget>
namespace Ui {
class UdpForm;
}

class UdpForm : public QWidget {
  Q_OBJECT

 public:
  explicit UdpForm(QWidget *parent = nullptr);
  ~UdpForm();

 private slots:
  void on_pushButton_clicked();
  void processPendingDatagram();

 private:
  Ui::UdpForm *ui;
  QUdpSocket *sender;
  QUdpSocket *receiver;
};

#endif  // UDPFORM_H
