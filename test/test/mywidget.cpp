#include "mywidget.h"

#include <QColorDialog>
#include <QDebug>
#include <QErrorMessage>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>

#include "mydialog.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MyWidget) {
  ui->setupUi(this);
  errordlg = new QErrorMessage(this);
}

MyWidget::~MyWidget() { delete ui; }

void MyWidget::on_pushButton_clicked() {
  // 先关闭主界面，其实他是隐藏起来了，并没有真正退出。然后新建Dialog对象
  close();
  MyDialog dlg;
  // 如果按下 “进入主窗口” 按钮，则再次显示主界面
  // 否则，因为现在没有显示的界面了，所以程序将退出
  if (dlg.exec() == QDialog::Accepted) show();
}

void MyWidget::on_pushButton_3_clicked() {  // 颜色对话框
  QColor color = QColorDialog::getColor(Qt::red, this, tr("颜色对话框"),
                                        QColorDialog::ShowAlphaChannel);
  qDebug() << "color: " << color;

  /* 等价代码
   * QColorDialog dialog(Qt::red, this);                // 创建对象
   * dialog.setOption(QColorDialog::ShowAlphaChannel);  // 显示alpha选项
   * dialog.exec();                                     // 以模态方式运行对话框
   * QColor color = dialog.currentColor();              // 获取当前颜色
   * qDebug() << "color:" << color;                     // 输出颜色信息
   */
}

void MyWidget::on_pushButton_4_clicked() {  // 文件对话框
  QString fileName = QFileDialog::getOpenFileName(
      this, tr("文件对话框"), "D:\\",
      tr("图片文件(*png *jpg);;文本文件(*txt);;全部文件(*)"));
  qDebug() << "fileName:" << fileName;

  QStringList fileNames = QFileDialog::getOpenFileNames(
      this, tr("文件对话框"), "F:\\");  // 默认选择所有类型
  qDebug() << "fileNames:" << fileNames;
}

void MyWidget::on_pushButton_6_clicked() {  // 字体对话框
  // ok 用于标记是否单击了OK按钮
  bool ok;
  QFont font = QFontDialog::getFont(&ok, this);
  // 如果单击了OK按钮，那么让“字体对话框”按钮使用新字体
  // 如果单击Cancel按钮，那么输出信息
  if (ok)
    ui->pushButton_6->setFont(font);
  else
    qDebug() << tr("没有选择字体");
}

void MyWidget::on_pushButton_5_clicked() {  // 输入对话框
  bool ok;
  // 获取字符串
  QString string =
      QInputDialog::getText(this, tr("输入字符串对话框"), tr("请输入用户名"),
                            QLineEdit::Normal, tr("admin"), &ok);
  if (ok) qDebug() << "string:" << string;
  // 获取整数
  int value = QInputDialog::getInt(this, tr("输入整数对话框"),
                                   tr("请输入-1000到1000之间的数值"), 100,
                                   -1000, 1000, 10, &ok);
  if (ok) qDebug() << "value:" << value;
  // 获取浮点数
  double value2 = QInputDialog::getDouble(this, tr("输入浮点数对话框"),
                                          tr("请输入-1000到1000之间的数值"),
                                          0.00, -1000, 1000, 2, &ok);
  if (ok) qDebug() << "value2:" << value2;
  QStringList items;
  items << tr("条目1") << tr("条目2");
  // 获取条目
  QString item =
      QInputDialog::getItem(this, tr("输入条目对话框"),
                            tr("请输入一个或多个条目"), items, 0, true, &ok);
  if (ok) qDebug() << "item:" << item;
}

void MyWidget::on_pushButton_8_clicked() {  // 消息对话框
  // 问题对话框
  int ret1 = QMessageBox::question(this, tr("问题对话框"), tr("你了解Qt吗？"),
                                   QMessageBox::Yes, QMessageBox::No);
  if (ret1 == QMessageBox::Yes) qDebug() << tr("问题！");
  // 提示对话框
  int ret2 = QMessageBox::information(this, tr("提示对话框"),
                                      tr("这是Qt书籍！"), QMessageBox::Ok);
  if (ret2 == QMessageBox::Ok) qDebug() << tr("提示！");
  // 警告对话框
  int ret3 = QMessageBox::warning(this, tr("警告对话框"), tr("不能提前结束！"),
                                  QMessageBox::Abort);
  if (ret3 == QMessageBox::Abort) qDebug() << tr("警告！");
  // 错误对话框
  int ret4 = QMessageBox::critical(this, tr("严重错误对话框"),
                                   tr("发现一个严重错误！现在要关闭所有文件"),
                                   QMessageBox::YesAll);
  if (ret4 == QMessageBox::YesAll) qDebug() << tr("错误");
  // 关于对话框
  QMessageBox::about(this, tr("关于对话框"),
                     tr("yafeilinux致力于Qt及Qt Creator的普及工作"));
}

void MyWidget::on_pushButton_7_clicked() {  // 进度对话框
  QProgressDialog dialog(
      tr("文件复制进度"), tr("取消"), 0, 500000,
      this);  // 标签内容、取消按钮文本、最小值、最大值、父窗口
  dialog.setWindowTitle(tr("进度对话框"));    // 设置窗口标题
  dialog.setWindowModality(Qt::WindowModal);  // 将对话框设置为模态
  dialog.show();
  for (int i = 0; i < 500000; ++i) {    // 演示复制进度
    dialog.setValue(i);                 // 设置进度条的当前值
    QCoreApplication::processEvents();  // 避免界面冻结
    if (dialog.wasCanceled()) break;    // 按下取消按钮则中断
  }
  dialog.setValue(500000);  // 这样才能显示100%，因为for循环中少加了一个数
  qDebug() << tr("复制结束");
}

void MyWidget::on_pushButton_10_clicked() {  // 错误信息对话框
  errordlg->setWindowTitle(tr("错误信息对话框"));
  errordlg->showMessage(tr("这里是出错信息！"));
}

void MyWidget::on_pushButton_9_clicked() {  // 向导对话框
  QWizard wizard(this);
  wizard.setWindowTitle(tr("向导对话框"));
  wizard.addPage(createPage1());  // 添加向导页面
  wizard.addPage(createPage2());
  wizard.addPage(createPage3());
  wizard.exec();
}

QWizardPage *MyWidget::createPage1() {  // 向导页面1
  QWizardPage *page = new QWizardPage;
  page->setTitle(tr("介绍"));
  return page;
}

QWizardPage *MyWidget::createPage2() {  // 向导页面2
  QWizardPage *page = new QWizardPage;
  page->setTitle(tr("用户选择信息"));
  return page;
}

QWizardPage *MyWidget::createPage3() {  // 向导页面3
  QWizardPage *page = new QWizardPage;
  page->setTitle(tr("结束"));
  return page;
}
