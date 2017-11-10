#include "prismarec.h"
#include "ui_prismarec.h"
#include <math.h>

PrismaRec::PrismaRec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrismaRec)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

PrismaRec::~PrismaRec()
{
    delete ui;
}

void line (int x0, int y0, int x1, int y1, QPainter & painter)
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
void dibujaPrismaRec(QPainter & painter){

    int medida = 40;
    int medida2 = 80;
    int medida3 = 40;

    int x0 = 0;
    int y0 = medida;
    int x1 = medida;
    int y1 = medida;
    int x2 = 0;
    int y2 = -medida2;
    int x3 = medida;
    int y3 = -medida2;


    int x4 = x0 + medida3;
    int y4 = y0 - medida;
    int x5 = x1 + medida3;
    int y5 = y1 - medida;
    int x6 = x2 + medida3;
    int y6 = y2 - medida;
    int x7 = x3 + medida3;
    int y7 = y3 - medida;

    line(x0,y0,x1,y1,painter);
    line(x2,y2,x3,y3,painter);
    line(x2,y2,x0,y0,painter);
    line(x3,y3,x1,y1,painter);

    line(x4,y4,x5,y5,painter);
    line(x6,y6,x7,y7,painter);
    line(x6,y6,x4,y4,painter);
    line(x7,y7,x5,y5,painter);

    line(x0,y0,x4,y4,painter);
    line(x1,y1,x5,y5,painter);
    line(x2,y2,x6,y6,painter);
    line(x3,y3,x7,y7,painter);

}

void PrismaRec::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if(dibuja) {

        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujaPrismaRec(painter);
        }
    }
}

void PrismaRec::on_dibujar_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}

void PrismaRec::on_trasladar_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();

}

void PrismaRec::on_rotar_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}

void PrismaRec::on_zoom_out_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}

void PrismaRec::on_zoom_in_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}

void PrismaRec::on_horizontal_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}

void PrismaRec::on_vertical_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}
