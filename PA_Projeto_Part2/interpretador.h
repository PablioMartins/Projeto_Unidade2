#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include "FiguraGeometrica.h"
#include <vector>
#include <string>

class Interpretador{
    int dimX, dimY, dimZ;
    float r, g, b, a;
public:
    Interpretador();
    std::vector<FiguraGeometrica*> parse(std::string filename);
    int getdimX();
    int getdimY();
    int getdimZ();
};

#endif // INTERPRETADOR_H
