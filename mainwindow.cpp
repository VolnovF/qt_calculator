#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->lineEdit_Expression, SIGNAL(returnPressed()), this, SLOT(on_pushButton_Calculate_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Calculate_clicked()
{
    QString str{ ui->lineEdit_Expression->text() };
    str = str.simplified();
    bool ok{ true };

    QQueue<Token*> infixTokens{};
    QObject parent{};
    Tokenize(str, infixTokens, &parent, &ok);
    if( !ok )
    {
        ui->lineEdit_Expression->setText( QString("Err") );
        return;
    }

    QQueue<Token*> rpnTokens{};
    ToRPN(infixTokens, rpnTokens, &ok);
    if( !ok )
    {
        ui->lineEdit_Expression->setText( QString("Err") );
        return;
    }

    double result{ executeRPN(rpnTokens, &ok) };
    if( !ok )
    {
        ui->lineEdit_Expression->setText( QString("Err") );
        return;
    }
    else
    {
        ui->lineEdit_Expression->setText( QString::number(result) );;
        ui->listWidget_History->addItem( str );
    }
}

void MainWindow::addInExpression(QString text)
{
    QString newText{ ui->lineEdit_Expression->text().append(text) };
    ui->lineEdit_Expression->setText( newText );
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!ui->lineEdit_Expression->hasFocus())
    {
        switch (event->key())
        {
            case Qt::Key::Key_0:
                on_pushButton_Num0_clicked();
                break;
            case Qt::Key::Key_1:
                on_pushButton_Num1_clicked();
                break;
            case Qt::Key::Key_2:
                on_pushButton_Num2_clicked();
                break;
            case Qt::Key::Key_3:
                on_pushButton_Num3_clicked();
                break;
            case Qt::Key::Key_4:
                on_pushButton_Num4_clicked();
                break;
            case Qt::Key::Key_5:
                on_pushButton_Num5_clicked();
                break;
            case Qt::Key::Key_6:
                on_pushButton_Num6_clicked();
                break;
            case Qt::Key::Key_7:
                on_pushButton_Num7_clicked();
                break;
            case Qt::Key::Key_8:
                on_pushButton_Num8_clicked();
                break;
            case Qt::Key::Key_9:
                on_pushButton_Num9_clicked();
                break;

            case Qt::Key::Key_ParenLeft:
                on_pushButton_OpenParenthesis_clicked();
                break;
            case Qt::Key::Key_ParenRight:
                on_pushButton_CloseParenthesis_clicked();
                break;
            default:
                break;
        }
    }
    if(event->key() == Qt::Key::Key_Enter)
    {
        on_pushButton_Calculate_clicked();
    }
}

void MainWindow::on_listWidget_History_itemClicked(QListWidgetItem *item)
{
    ui->lineEdit_Expression->setText( item->text() );
}


void MainWindow::on_pushButton_AllClear_clicked()
{
    ui->lineEdit_Expression->clear();
}


void MainWindow::on_pushButton_OpenParenthesis_clicked()
{
    addInExpression("(");
}

void MainWindow::on_pushButton_CloseParenthesis_clicked()
{
    addInExpression(")");
}


void MainWindow::on_pushButton_Division_clicked()
{
    addInExpression("/");
}


void MainWindow::on_pushButton_Power_clicked()
{
    addInExpression("^");
}


void MainWindow::on_pushButton_Multiply_clicked()
{
    addInExpression("*");
}


void MainWindow::on_pushButton_Minus_clicked()
{
    addInExpression("-");
}


void MainWindow::on_pushButton_Plus_clicked()
{
    addInExpression("+");
}


void MainWindow::on_pushButton_Num1_clicked()
{
    addInExpression("1");
}


void MainWindow::on_pushButton_Num2_clicked()
{
    addInExpression("2");
}


void MainWindow::on_pushButton_Num3_clicked()
{
    addInExpression("3");
}


void MainWindow::on_pushButton_Num4_clicked()
{
    addInExpression("4");
}


void MainWindow::on_pushButton_Num5_clicked()
{
    addInExpression("5");
}


void MainWindow::on_pushButton_Num6_clicked()
{
    addInExpression("6");
}


void MainWindow::on_pushButton_Num7_clicked()
{
    addInExpression("7");
}


void MainWindow::on_pushButton_Num8_clicked()
{
    addInExpression("8");
}


void MainWindow::on_pushButton_Num9_clicked()
{
    addInExpression("9");
}


void MainWindow::on_pushButton_Dot_clicked()
{
    addInExpression(".");
}


void MainWindow::on_pushButton_Num0_clicked()
{
    addInExpression("0");
}

