#include "prismatri.h"
#include "ui_prismatri.h"
#include <math.h>

PrismaTri::PrismaTri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrismaTri)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

PrismaTri::~PrismaTri()
{
    delete ui;
}

void linea (int x0, int y0, int x1, int y1, QPainter & painter)
{
    int sx, sy, e2;
  int dx =  abs (x1 - x0);
    int dy = -abs (y1 - y0);
        if(x0 < x1)
        {
            sx = 1;
        }
        else
        {
                sx = -1;
        }
        if(y0 < y1)
        {
            sy = 1;
        }
        else
        {
                sy = -1;
        }

  int err = dx + dy;

  for (int i; i < dy; i++)
    {
    painter.drawPoint(x0,y0);
    if (x0 == x1 && y0 == y1)
        {
            break;
        }
        else
        {
            e2 = 2 * err;
        }

    if (e2 >= dy)
        {
            err += dy; x0 += sx;
         }
    if (e2 <= dx)
         {
             err += dx; y0 += sy;
          }
}
}

void dibujarPrismaTri(QPainter & painter){

    int distancia = 50;
    int distancia_2 = distancia*2;
    int distancia_3 = 70;

    int x1 = 0;
    int y1 = -distancia_2;
    int x2 = -distancia;
    int y2 = -distancia_3;
    int x3 = distancia;
    int y3 = -distancia_3;
    int _x1 = 0;
    int _y1 = -distancia_2+distancia_2;
    int _x2 = -distancia;
    int _y2 = -distancia_3+distancia_2;
    int _x3 = distancia;
    int _y3 = -distancia_3+distancia_2;

   linea(x1,y1,x2,y2,painter);
   linea(x1,y1,x3,y3, painter);
   linea(x2,y2,x3,y3,painter);
   linea(_x1,_y1,_x2,_y2,painter);
   linea(_x1,_y1,_x3,_y3,painter);
   linea(_x2,_y2,_x3,_y3,painter);
   linea(x1,y1,_x1,_y1,painter);
   linea(x2,y2,_x2,_y2,painter);
   linea(_x3,_y3,x3,y3,painter);

}
void PrismaTri::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);


    if(dibuja) {

        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujarPrismaTri(painter);
        }

    }

}
void PrismaTri::on_dibujar_clicked(){
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}

void PrismaTri::on_trasladar_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();

}

void PrismaTri::on_rotar_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}

void PrismaTri::on_zoom_out_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}

void PrismaTri::on_zoom_in_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}

void PrismaTri::on_horizontal_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}
void PrismaTri::on_vertical_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}

