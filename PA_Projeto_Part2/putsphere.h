#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "FiguraGeometrica.h"
#include "sculptor.h"


class PutSphere: public FiguraGeometrica{
int xcenter,ycenter,zcenter,radius;
public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    ~PutSphere(){};
    void Draw(sculptor &t);
};

#endif // PUTSPHERE_H
