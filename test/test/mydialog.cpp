#include "mydialog.h"

#include <QCompleter>
#include <QDebug>
#include <QMenu>

#include "ui_mydialog.h"

MyDialog::MyDialog(QDialog *parent) : QDialog(parent), ui(new Ui::MyDialog) {
  ui->setupUi(this);
  connect(ui->pb_showChild, &QPushButton::clicked, this,
          &MyDialog::on_pb_showChild_clicked);
  QString string = tr("标题太长，需要进行省略");
  QString str =
      ui->label_2->fontMetrics().elidedText(string, Qt::ElideRight, 180);
  ui->label_2->setText(str);

  ui->pushBtn1->setText(tr("&nihao"));
  ui->pushBtn2->setText(tr("帮助(&H)"));
  ui->pushBtn2->setIcon(QIcon("../test/images/help.png"));
  ui->pushBtn3->setText(tr("z&oom"));
  QMenu *menu = new QMenu(this);
  menu->addAction(QIcon("../test/images/help.png"), tr("放大"));
  ui->pushBtn3->setMenu(menu);

  /* QLineEdit 3输入验证 */
  QValidator *validator =
      new QIntValidator(100, 999, this);  // 新建验证器，指定范围100-999
  ui->lineEditt3->setValidator(validator);  // 在行编辑器中使用验证器
  /* 正则
   * QRegExp rx("-?\\d{1,3}"); // 开始输入 '-' 号或者不输入，然后输入1~3个数字
   * QValidator *validator = new QRegExpValidator(rx, this);
   */

  /* QLineEdit 4自动补全 */
  QStringList wordList;
  wordList << "Qt"
           << "Qt Creator" << tr("你好");
  QCompleter *completer = new QCompleter(wordList, this);  //新建自动完成器
  completer->setCaseSensitivity(Qt::CaseInsensitive);  //设置大小写不敏感
  ui->lineEditt4->setCompleter(completer);

  /* QDateTimeEdit */
  ui->dateTimeEdit->setDateTime(
      QDateTime::currentDateTime());  // 设置时间为现在的系统时间
  ui->dateTimeEdit->setDisplayFormat(
      tr("yyyy年MM月dd日ddd HH时mm分ss秒"));  // 设置时间的显示格式

  ui->textEdit_2->hide();  // 让文本编辑器隐藏，也可以使用setVisible(false)函数
}

MyDialog::~MyDialog() { delete ui; }

void MyDialog::on_pb_showChild_clicked() {
  QDialog *dialog = new QDialog(this);
  dialog->show();
}

void MyDialog::on_pushButton_clicked() { accept(); }

void MyDialog::on_pushBtn1_toggled(bool checked) {
  qDebug() << tr("按钮1是否按下:") << checked;
}

void MyDialog::on_lineEditt2_returnPressed() {  // 回车键按下信号的槽
  ui->lineEditt3->setFocus();                   // 让lineEdit3获得焦点
  qDebug() << ui->lineEditt2->text();           // 输出lineEdit2的内容
  qDebug() << ui->lineEditt2->displayText();  // 输入胡lineEdit2显示的内容
}

void MyDialog::on_pushButton_10_toggled(bool checked) {  //显隐窗口按钮
  ui->textEdit_2->setVisible(checked);  //设置文本编辑器的显示和展示
  if (checked)
    ui->pushButton_10->setText(tr("隐藏可扩展窗口"));
  else
    ui->pushButton_10->setText(tr("显示可扩展窗口"));
}
