#include "arcos.h"
#include "ui_arcos.h"
#include <QMessageBox>
#include <math.h>

#define PI 3.14159265

Arco::Arco(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arcos)
{
    this->setFixedSize(800,800);
    ui->setupUi(this);
    xCentro = 400.0;
    yCentro = 400.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

Arco::~Arco()
{
    delete ui;
}


void dibujarArco(QPainter & painter) {


    int xc,yc,x,y,p,r;

      xc=0;
      yc=0;
      r=50;
      x = 0;
      y = r;
      p = 1-r;

      while(x<=y)
      {
        if(p<0)
        {
        x++;
        p += 2*x +1;
        }
        else{
        x++;
        y--;
        p += 2*x - 2*y +1;
        }
        painter.drawPoint(xc+x,yc+y);
        painter.drawPoint(xc+y,yc+x);
        painter.drawPoint(xc+x,yc-y);
        painter.drawPoint(xc+y,yc-x);


      }


    }

void Arco::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);

    if (dibuja) {
        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujarArco(painter);;

        }

    }

}

void Arco::on_dibujar_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}//cierre del boton dibujar

void Arco::on_trasladar_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();

}//cierre del boton de trasladar

void Arco::on_rotar_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}//cierre del boton de rotar

void Arco::on_zoom_in_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}//cierre del boton de zoom in

void Arco::on_zoom_out_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}//cierre del boton de zoom out

void Arco::on_horizontal_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}//cierre del boton de reflexion vertical

void Arco::on_vertical_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}//cierre del boton de reflexion horizontal
