#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_3_clicked()));

    // Inicializar administrarNeuronas
    administrarNeuronas = administradora();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString valor1Str = ui->lineEdit->text();
    QString valor2Str = ui->lineEdit_2->text();
    QString valor3Str = ui->lineEdit_3->text();
    QString valor4Str = ui->lineEdit_4->text();
    QString valor5Str = ui->lineEdit_5->text();
    QString valor6Str = ui->lineEdit_6->text();
    QString valor7Str = ui->lineEdit_7->text();

    // Verificar si algún campo está vacío antes de continuar
    if (valor1Str.isEmpty() || valor2Str.isEmpty() || valor3Str.isEmpty() ||
        valor4Str.isEmpty() || valor5Str.isEmpty() || valor6Str.isEmpty() || valor7Str.isEmpty()) {
        QMessageBox::warning(this, "Campos Vacíos", "Por favor, complete todos los campos.");
        return;
    }

    // Convertir valores a números
    int valor1 = valor1Str.toInt();
    float valor2 = valor2Str.toFloat();
    int valor3 = valor3Str.toInt();
    int valor4 = valor4Str.toInt();
    int valor5 = valor5Str.toInt();
    int valor6 = valor6Str.toInt();
    int valor7 = valor7Str.toInt();

    Neurona n;
    n.setID(valor1);
    n.setVolt(valor2);
    n.setPX(valor3);
    n.setPY(valor4);
    n.setRed(valor5);
    n.setGreen(valor7);
    n.setBlue(valor6);

    administrarNeuronas.agregarInicio(n);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
}


void MainWindow::on_actionOpen_triggered()
{
    QString Filename = QFileDialog::getOpenFileName(this, tr("Abrir Archivo"), "/home", tr("Images (*.png *.xpm *.jpg"));
}



void MainWindow::on_pushButton_3_clicked()
{
    QString valor1Str = ui->lineEdit->text();
    QString valor2Str = ui->lineEdit_2->text();
    QString valor3Str = ui->lineEdit_3->text();
    QString valor4Str = ui->lineEdit_4->text();
    QString valor5Str = ui->lineEdit_5->text();
    QString valor6Str = ui->lineEdit_6->text();
    QString valor7Str = ui->lineEdit_7->text();

    // Verificar si algún campo está vacío antes de continuar
    if (valor1Str.isEmpty() || valor2Str.isEmpty() || valor3Str.isEmpty() ||
        valor4Str.isEmpty() || valor5Str.isEmpty() || valor6Str.isEmpty() || valor7Str.isEmpty()) {
        QMessageBox::warning(this, "Campos Vacíos", "Por favor, complete todos los campos.");
        return;
    }

    // Convertir valores a números
    int valor1 = valor1Str.toInt();
    float valor2 = valor2Str.toFloat();
    int valor3 = valor3Str.toInt();
    int valor4 = valor4Str.toInt();
    int valor5 = valor5Str.toInt();
    int valor6 = valor6Str.toInt();
    int valor7 = valor7Str.toInt();

    Neurona n;
    n.setID(valor1);
    n.setVolt(valor2);
    n.setPX(valor3);
    n.setPY(valor4);
    n.setRed(valor5);
    n.setGreen(valor7);
    n.setBlue(valor6);

    administrarNeuronas.agregarFinal(n);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
}



void MainWindow::on_pushButton_2_clicked()
{
    QString contenido = QString::fromStdString(administrarNeuronas.mostrar());
    ui->plainTextEdit->setPlainText(contenido);
}

