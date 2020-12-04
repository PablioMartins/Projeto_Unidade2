#include "interpretador.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

Interpretador::Interpretador()
{

}

std::vector<FiguraGeometrica*> Interpretador:: parse(std::string filename){
    std::vector<FiguraGeometrica*> figs;
    std::ifstream fin;
    std::stringstream ss;
    std::string s, token;

    fin.open(filename.c_str());

    if(!fin.is_open()){
        std::cout << "O Arquivo "<< filename <<" nao foi Aberto." << std::endl;
        exit(0);
    }

    while(fin.good()){
        std::getline(fin, s);
        if(fin.good()){
            ss.clear();
            ss.str(s);

            ss >> token;
            //std::cout << token << std :: endl;
            if(ss.good()){
                if(token.compare("dim") == 0 || token.compare("Dim") == 0){
                    ss >> dimX >> dimY >> dimZ;
                }
                else if(token.compare("putvoxel") == 0 || token.compare("Putvoxel") == 0 || token.compare("PutVoxel") == 0){
                    int x, y, z;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    figs.push_back(new PutVoxel(x,y,z,r,g,b,a));
                }
                else if(token.compare("cutvoxel") == 0 || token.compare("Cutvoxel") == 0 || token.compare("CutVoxel") == 0){
                    int x, y, z;
                    ss >> x >> y >> z;
                    figs.push_back(new CutVoxel(x,y,z));
                }
                else if(token.compare("putbox") == 0 || token.compare("Putbox") == 0 || token.compare("PutBox") == 0){
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
                }
                else if(token.compare("cutbox") == 0 || token.compare("Cutbox") == 0 || token.compare("CutBox") == 0){
                    int x0, y0, z0, x1, y1, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
                }
                else if(token.compare("putsphere") == 0 || token.compare("Putsphere") == 0 || token.compare("PutSphere") == 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                    figs.push_back(new PutSphere(xcenter, ycenter, zcenter, radius,r,g,b,a));
                }
                else if(token.compare("cutsphere") == 0 || token.compare("Cutsphere") == 0 || token.compare("CutSphere") == 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    figs.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
                }
                else if(token.compare("putellipsoid") == 0 || token.compare("Putellipsoid") == 0 || token.compare("PutEllipsoid") == 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                    figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz,r,g,b,a));
                }
                else if(token.compare("cutellipsoid") == 0 || token.compare("Cutellipsoid") == 0 || token.compare("CutEllipsoid") == 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                    figs.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
                }
            }
        }
    }
    return (figs);
}

int Interpretador :: getdimX(){
    return dimX;
}

int Interpretador :: getdimY(){
    return dimY;
}

int Interpretador :: getdimZ(){
    return dimZ;
}
