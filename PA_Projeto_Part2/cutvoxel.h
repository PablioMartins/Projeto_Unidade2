#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "FiguraGeometrica.h"
#include "sculptor.h"

class CutVoxel: public FiguraGeometrica{
    int x,y,z;
public:
    CutVoxel(int x, int y, int z);
    void Draw(sculptor &t);
};

#endif // CUTVOXEL_H
