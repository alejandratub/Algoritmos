#ifndef PRISMAREC_H
#define PRISMAREC_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "transformaciones.h"

namespace Ui {
class PrismaRec;
}

class PrismaRec : public QDialog
{
    Q_OBJECT

public:
    explicit PrismaRec(QWidget *parent = 0);
    ~PrismaRec();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_dibujar_clicked();
    void on_trasladar_clicked();
    void on_rotar_clicked();
    void on_zoom_in_clicked();
    void on_zoom_out_clicked();
    void on_horizontal_clicked();
    void on_vertical_clicked();

private:
    Ui::PrismaRec *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> vecTrans;
    Transformaciones trans;

};

#endif // PRISMAREC_H
