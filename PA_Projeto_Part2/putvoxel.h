#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "FiguraGeometrica.h"
#include "sculptor.h"


class PutVoxel: public FiguraGeometrica{
int x, y, z;
public:
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
    ~PutVoxel(){};
    void Draw(sculptor &t);
};

#endif // PUTVOXEL_H
