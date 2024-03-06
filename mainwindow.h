#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QKeyEvent>

#include "token/token.h"
#include "token/tokenizer.h"
#include "math/rpn.h"
#include "math/executerpn.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Calculate_clicked();

    void on_listWidget_History_itemClicked(QListWidgetItem *item);

    void on_pushButton_AllClear_clicked();

    void on_pushButton_OpenParenthesis_clicked();
    void on_pushButton_CloseParenthesis_clicked();
    void on_pushButton_Division_clicked();
    void on_pushButton_Power_clicked();
    void on_pushButton_Multiply_clicked();
    void on_pushButton_Minus_clicked();
    void on_pushButton_Plus_clicked();
    void on_pushButton_Num1_clicked();
    void on_pushButton_Num2_clicked();
    void on_pushButton_Num3_clicked();
    void on_pushButton_Num4_clicked();
    void on_pushButton_Num5_clicked();
    void on_pushButton_Num6_clicked();
    void on_pushButton_Num7_clicked();
    void on_pushButton_Num8_clicked();
    void on_pushButton_Num9_clicked();
    void on_pushButton_Dot_clicked();
    void on_pushButton_Num0_clicked();

private:
    Ui::MainWindow *ui;
    void addInExpression(QString text);

protected:
    void keyPressEvent(QKeyEvent* event) override;
};
#endif // MAINWINDOW_H
