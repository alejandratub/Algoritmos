#include "cubo.h"
#include "ui_cubo.h"
#include <math.h>

Cubo::Cubo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cubo)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

Cubo::~Cubo()
{
    delete ui;
}

void Bresenham (int x0, int y0, int x1, int y1, QPainter & painter)
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
void dibujaCubo(QPainter &painter){
    int distancia = 40;

    int x1 = -distancia;
    int y1 = distancia;
    int x2 = distancia;
    int y2 = distancia;
    int x3 = -distancia;
    int y3 = -distancia;
    int x4 = distancia;
    int y4 = -distancia;

    int distancia_2 = (x2-x1)/2;

    int _x1 = x1 + distancia_2;
    int _y1 = y1 - distancia_2;
    int _x2 = x2 + distancia_2;
    int _y2 = y2 - distancia_2;
    int _x3 = x3 + distancia_2;
    int _y3 = y3 - distancia_2;
    int _x4 = x4 + distancia_2;
    int _y4 = y4 - distancia_2;

    Bresenham(x1, y1, x2, y2, painter);
    Bresenham(x1, y1, x3, y3, painter);
    Bresenham(x2, y2, x4, y4, painter);
    Bresenham(x3, y3, x4, y4, painter);
    Bresenham(_x1, _y1, _x2, _y2, painter);
    Bresenham(_x1, _y1, _x3, _y3, painter);
    Bresenham(_x2, _y2, _x4, _y4,painter);
    Bresenham(_x3, _y3, _x4, _y4, painter);
    Bresenham(x1, y1, _x1, _y1,painter);
    Bresenham(x2, y2, _x2, _y2,painter);
    Bresenham(x3, y3, _x3, _y3,painter);
    Bresenham(x4, y4, _x4, _y4,painter);

}

void Cubo::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja) {

        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujaCubo(painter);

        }//Cierre del for

    }//Cierre del if que checa dibuja

}//cierre de paintEvent

void Cubo::on_dibujar_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}

void Cubo::on_trasladar_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();

}

void Cubo::on_rotar_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}

void Cubo::on_zoom_out_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}

void Cubo::on_zoom_in_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}

void Cubo::on_horizontal_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}

void Cubo::on_vertical_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}
