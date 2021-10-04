#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void startRequest(QUrl url);

 private slots:
  void httpFinished();
  void httpReadyRead();
  void updateDataReadProgress(qint64, qint64);

  void on_pushButton_clicked();
  void loopedUp(const QHostInfo &host);
  void handleServers();

 private:
  Ui::MainWindow *ui;
  QNetworkAccessManager *manager;
  QNetworkReply *reply;
  QUrl url;
  QFile *file;
  QDnsLookup *dns;
};
#endif  // MAINWINDOW_H
