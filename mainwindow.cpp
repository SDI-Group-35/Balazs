#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "polygonDraw.h"
#include <iostream>
#include <QGraphicsLineItem>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    pmap=new pixelmap(this);
    scene = new QGraphicsScene(this);
    ui -> graphicsView -> setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//when load image button is clicked
void MainWindow::on_actionLoad_triggered()
{
    pmap -> loadImg(scene);

    scene -> addItem(pmap);
}


//draws lines
void MainWindow:: drawLines(const QPointF &firstP , const QPointF &secondP)
{
    QGraphicsLineItem *lines = scene -> addLine(firstP.x(), firstP.y(), secondP.x(), secondP.y(), pen);

    pmap -> lineV.push_back(lines);
}

//draw polygon
void MainWindow:: drawPolygon(const QPolygonF &polygon)
{

    polygonDraw *pointer = new polygonDraw(polygon, this);

    pointer -> setPen(pen);

    scene -> addItem(pointer);

    for (const QGraphicsLineItem* line: pmap -> lineV)
    {
        delete line;
    }

    pointer -> setFlag(QGraphicsItem::ItemIsMovable);
}



void MainWindow::on_radioButton_clicked()
{
    pmap -> sides = 1;
}
