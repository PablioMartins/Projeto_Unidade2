#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

class FiguraGeometrica{
protected:
    float r,g,b,a;
public:
    virtual ~FiguraGeometrica(){};
    virtual void Draw(sculptor &t)=0;
};


#endif // FIGURAGEOMETRICA_H
