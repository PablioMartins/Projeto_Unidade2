#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "Voxel.h"

class sculptor {
protected:
    Voxel ***v;

    int nx, ny, nz; // Dimensions
    float r, g, b, a; // Current drawing color
public:
    sculptor(int _nx, int _ny, int _nz);
    ~sculptor();
    void setColor(float r, float g, float b, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void writeOFF(char* filename);
    void LimpaVoxel();
};

void confere(int &x, int &y);

#endif // SCUPTOR_H
