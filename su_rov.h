#ifndef SU_ROV_H
#define SU_ROV_H

#include <QObject>
#include <QTimer>

#include "KX_Pult/kx_protocol.h"
#include "KX_Pult/qkx_coeffs.h"

#define MODEL_N 3

extern double X[2000][2];
extern QVector<double> K;

class SU_ROV : public QObject
{
    Q_OBJECT
public:
    explicit SU_ROV(QObject *parent = nullptr);

public slots:
    void tick();

signals:

private:
    Qkx_coeffs *K_Protocol;
    x_protocol *X_Protocol;

    QTimer time;
    float T;

    double Jz;
    double Cwz1, Cwz2;
    double metaH;
    double m;
    double g;

    double x[MODEL_N];
    double a[MODEL_N];
    double da[MODEL_N];

    void f_x_u(double uz);
    void runge(double uz, double h=0.01);
    void resetModel();
};

#endif // SU_ROV_H
