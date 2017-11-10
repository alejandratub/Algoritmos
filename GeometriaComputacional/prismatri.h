#ifndef PRISMATRI_H
#define PRISMATRI_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "transformaciones.h"

namespace Ui {
class PrismaTri;
}

class PrismaTri : public QDialog
{
    Q_OBJECT

public:
    explicit PrismaTri(QWidget *parent = 0);
    ~PrismaTri();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_dibujar_clicked();
    void on_rotar_clicked();
    void on_trasladar_clicked();
    void on_zoom_in_clicked();
    void on_zoom_out_clicked();
    void on_horizontal_clicked();
    void on_vertical_clicked();

private:
    Ui::PrismaTri *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> vecTrans;
    Transformaciones trans;
};

#endif // PRISMATRI_H
