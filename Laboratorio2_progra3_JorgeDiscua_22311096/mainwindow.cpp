#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QTextStream>
#include <QChar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::crearPiramide(int n)
{
    QString resultado;
    for (int i = 1; i <= n; ++i) {

        for (int j = 0; j < n - i; ++j) {
            resultado += ' ';
        }

        for (int k = 0; k < 2 * i - 1; ++k) {
            resultado += '*';
        }

        resultado += '\n';
    }
    return resultado;
}

int MainWindow::verificarTarjeta(QString tarjetaStr)
{
    std::reverse(tarjetaStr.begin(), tarjetaStr.end());

    int sumaTotal = 0;
    for (int i = 0; i < tarjetaStr.length(); ++i) {
        int digito = tarjetaStr[i].digitValue();
        if (i % 2 == 1) {
            digito *= 2;
            if (digito > 9) {
                digito = (digito / 10) + (digito % 10);
            }
        }
        sumaTotal += digito;
    }

    return (sumaTotal % 10 == 0) ? 1 : 0;
}

int MainWindow::letraABinario(char letra)
{
    QString binario;
    int valor = static_cast<int>(letra);

    for (int i = 7; i >= 0; --i) {
        binario += (valor & (1 << i)) ? '1' : '0';
    }

    return binario.toInt();
}

int MainWindow::letraADecimal(char letra)
{
    return static_cast<int>(letra);
}

QString MainWindow::letraAHexadecimal(char letra)
{
    int valor = static_cast<int>(letra);
    QString hexadecimal = QString::number(valor, 16).toUpper();
    return hexadecimal;
}

char MainWindow::binarioALetra(QString binario)
{
    int valor = 0;
    int longitud = binario.length();

    for (int i = 0; i < longitud; ++i) {
        if (binario[i] == '1') {
            valor += (1 << (longitud - i - 1));
        }
    }

    return static_cast<char>(valor);
}

QChar MainWindow::decimalALetra(int decimal)
{
    return QChar(decimal);
}

char MainWindow::hexadecimalALetra(QString hexadecimal)
{
    bool xd;
    int valor = hexadecimal.toInt(&xd, 16);
    if (!xd) {
        return '\0'; //por si falla
    }
    return static_cast<char>(valor);
}



void MainWindow::on_pushButton_5_clicked()
{
    QString piramide = crearPiramide(ui->piramideSpinBo->value());
    ui->mostrarPiramide->setText(piramide);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->piramideSpinBo->setValue(0);
    ui->mostrarPiramide->setText("");
}


void MainWindow::on_pushButton_4_clicked()
{
    exit(0);
}


void MainWindow::on_pushButton_6_clicked()
{

    int resultado = verificarTarjeta(ui->lineEditTarjeta->text());
    if (resultado == 1){
        ui->resultadoTarjeta->setText("Tarjeta valida");
    }else{
        ui->resultadoTarjeta->setText("Tarjeta invalida");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEditTarjeta->setText("");
    ui->resultadoTarjeta->setText("");
}


void MainWindow::on_pushButton_13_clicked()
{

    int resultado = letraABinario(ui->charBinario->text().toLatin1().data()[0]);
    ui->charBinarioLine->setText(QString::number(resultado));
}


void MainWindow::on_pushButton_14_clicked()
{
    int resultado = letraADecimal(ui->charDecimal->text().toLatin1().data()[0]);
    ui->charDecimalLabel->setText(QString::number(resultado));
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->charBinario->setText("");
    ui->charBinarioLine->setText("");
}


void MainWindow::on_pushButton_15_clicked()
{
    ui->charHexadecimalLabel->setText(letraAHexadecimal(ui->charHexadecimal_2->text().toLatin1().data()[0]));
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->charDecimal->setText("");
    ui->charDecimalLabel->setText("");
}


void MainWindow::on_pushButton_16_clicked()
{
    char ch = binarioALetra(ui->BinarioChar->text());
    QString str(ch);
    ui->binarioCharLabel->setText(str);
}



void MainWindow::on_pushButton_17_clicked()
{
    bool ya;
    QChar ch = decimalALetra(ui->decimalChar->text().toInt(&ya,16));
    QString str(ch);
    ui->decimalCharLabel->setText(str);
    //qDebug() << "botoneando";
}


void MainWindow::on_pushButton_18_clicked()
{
    char ch = hexadecimalALetra(ui->hexadecimalChar->text());
    QString str(ch);
    ui->hexadecimalCharLine->setText(str);
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
    ui->BinarioChar->setText("");
    ui->binarioCharLabel->setText("");
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->charHexadecimal_2->setText("");
    ui->charHexadecimalLabel->setText("");
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
    ui->decimalChar->setText("");
    ui->decimalChar->setText("");
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(5);
    ui->hexadecimalChar->setText("");
    ui->hexadecimalCharLine->setText("");
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(0);
}

