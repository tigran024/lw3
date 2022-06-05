#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>
#include "rect.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    // Я сделал так, чтобы прямоугольник строился используя клавиши Shift и Control.
    // Таким образом можно изменить прямоугольник в процессе "попадания" в прямоугольник.
    if (event->modifiers() & Qt::ShiftModifier)
    {
        p[0] = new Rect(event->x(), event->y(), 0, 0);
        qDebug("x1 = %d, y1 = %d", event->x(), event->y());
        valid1 = true;
    }
    else if (event->modifiers() & Qt::ControlModifier)
    {
        p[1] = new Rect(event->x(), event->y(), 0, 0);
        qDebug("x2 = %d, y2 = %d", event->x(), event->y());
        valid2 = true;
    }
    else
    {
        if (valid1 & valid2) {
            qDebug("x = %d, y = %d", event->x(), event->y());
            int nx = event->x(), ny = event->y();
            QMessageBox msg;
            if (((p[2]->getX())<nx) && (nx<(p[2]->getX()+p[2]->getW())) && ((p[2]->getY())<ny) && (ny<(p[2]->getY()+p[2]->getH())))
                msg.setText("Попали");
            else msg.setText("Не попали");
            msg.exec();
        }
    }
    if (valid1 & valid2)
        p[2] = new Rect(((p[0]->getX() > p[1]->getX()) ? p[1]->getX() : p[0]->getX()), ((p[0]->getY()>p[1]->getY()) ? p[1]->getY() : p[0]->getY()),
            abs(p[0]->getX() - p[1]->getX()), abs(p[0]->getY() - p[1]->getY()));
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if (p[2])
        p[2]->draw(&painter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

