#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

// QT_BEGIN_NAMESPACE
namespace Ui {
class MyDialog;
}
// QT_END_NAMESPACE

class MyDialog : public QDialog {
  Q_OBJECT

 public:
  explicit MyDialog(QDialog *parent = nullptr);
  ~MyDialog();

 private slots:
  void on_pb_showChild_clicked();

  void on_pushButton_clicked();

  void on_pushBtn1_toggled(bool checked);

  void on_lineEditt2_returnPressed();

  void on_pushButton_10_toggled(bool checked);

  private:
  Ui::MyDialog *ui;
};
#endif  // MYDIALOG_H
