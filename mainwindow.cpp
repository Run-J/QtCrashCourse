#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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




void MainWindow::on_btnAdd_clicked()
{
    QString task = ui->lineEditTask->text().trimmed();
    if (task.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Task cannot be empty");
        return;
    }

    ui->listWidgetTasks->addItem(task);
    ui->lineEditTask->clear();
}


void MainWindow::on_btnDelete_clicked()
{
    QListWidgetItem *item = ui->listWidgetTasks->currentItem();
    if (!item) return;

    delete item;
}


void MainWindow::on_btnMarkDone_clicked()
{
    QListWidgetItem * item = ui->listWidgetTasks->currentItem();
    if (!item) return;

    item->setText("[Done]" + item->text());
    item->setForeground(Qt::gray);
}

