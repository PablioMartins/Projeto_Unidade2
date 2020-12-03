#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

sculptor::sculptor(int _nx, int _ny, int _nz)
{
    int i, j, k;
    nx = _nx; ny = _ny; nz = _nz;

    v = new Voxel**[nx];
    v[0] = new Voxel*[ny*nx];
    v[0][0] = new Voxel[nx*ny*nz];
    for(i = 1; i < nx; i++){
        v[i] = v[i-1] + ny;
    }

    for(j = 1; j < ny*nx; j++){
          v[0][j] = v[0][j-1] + nz;
    }


    for(i = 0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                v[i][j][k].isOn = false;
            }
         }
     }
}

sculptor::~sculptor()
{
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

void sculptor :: setColor(float r, float g, float b, float alpha){
    this->r = r; this->g = g; this->b = b; this->a = alpha;
}

void sculptor::putVoxel(int x, int y, int z)
{
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz){
        v[x][y][z].isOn = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }

}

void sculptor::cutVoxel(int x, int y, int z)
{
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz){
        v[x][y][z].isOn = false;
    }
}

void sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{

    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1; k++){
                putVoxel(i,j,k);
            }
        }
    }
}

void sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k < z1; k++){
                cutVoxel(i,j,k);
            }
        }
    }
}

void sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = xcenter - radius; i <= xcenter + radius; i++){
        for(int j = ycenter - radius; j <= ycenter + radius; j++){
            for(int k = zcenter - radius; k <= zcenter + radius; k++){
                if(sqrt(pow(i-xcenter,2)+pow(j-ycenter,2)+pow(k-zcenter,2)) <= radius){
                putVoxel(i,j,k);
                }
            }
        }
    }
}

void sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i = xcenter - radius; i <= xcenter + radius; i++){
        for(int j = ycenter - radius; j <= ycenter + radius; j++){
            for(int k = zcenter - radius; k <= zcenter + radius; k++){
                if(sqrt(pow(i-xcenter,2)+pow(j-ycenter,2)+pow(k-zcenter,2)) <= radius){
                cutVoxel(i,j,k);
                }
            }
        }
    }
}

void sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = xcenter - rx; i < xcenter + rx; i++){
        for(int j = ycenter - ry; j < ycenter + ry; j++){
            for(int k = zcenter - rz; k < zcenter + rz; k++){
                if(rx != 0 && ry != 0 && rz != 0){
                    if((sqrt(pow(i-xcenter,2)/pow(rx,2)+pow(j-ycenter,2)/pow(ry,2)+pow(k-zcenter,2)/pow(rz,2))) <= 1){
                    putVoxel(i,j,k);
                    }

                }
            }
        }
    }
}

void sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = xcenter - rx; i < xcenter + rx; i++){
        for(int j = ycenter - ry; j < ycenter + ry; j++){
            for(int k = zcenter - rz; k < zcenter + rz; k++){
                if((sqrt(pow(i-xcenter,2)/pow(rx,2)+pow(j-ycenter,2)/pow(ry,2)+pow(k-zcenter,2)/pow(rz,2))) <= 1){
                cutVoxel(i,j,k);
                }
            }
        }
    }
}

void sculptor::writeOFF(char *filename)
{
    //contador de voxels
    int i, j, k, cont = 0;

    for( i = 0; i < nx ; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                    if(v[i][j][k].isOn == true){
                        cont++;
                    }
            }
        }
    }

    ofstream arquivo;

    arquivo.open(filename);

    if(arquivo.is_open() == 0)printf("Erro nao foi aberto\n");

    arquivo << "OFF" << endl;
    arquivo << cont*8 << " " << cont*6 << " " << "0" <<endl;

    for(i = 0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn == true){
                arquivo << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                arquivo << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                arquivo << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                arquivo << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                arquivo << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                arquivo << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                arquivo << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                arquivo << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                }
            }
        }
    }
    int ponto = 0;
    arquivo << fixed << setprecision(2);
    for(i = 0; i < nx; i++){
        for(j = 0; j < ny; j++){
            for(k = 0; k < nz; k++){
                if(v[i][j][k].isOn == true){
                //P0 P3 P2 P1
                arquivo << 4 << " " << ponto << " " <<  ponto+3 << " " << ponto+2 << " " << ponto+1 << " ";
                arquivo << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                //P4 P5 P6 P7
                arquivo << 4 << " " << ponto+4 << " " << ponto+5 << " " << ponto+6 << " " << ponto+7 << " ";
                arquivo << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                //P0 P1 P5 P4
                arquivo << 4 << " " << ponto << " " << ponto+1 << " " << ponto+5 << " " << ponto+4 << " ";
                arquivo << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                //P0 P4 P7 P3
                arquivo << 4 << " " << ponto << " " << ponto+4 << " " << ponto+7 << " " << ponto+3 << " ";
                arquivo << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                //P7 P6 P2 P3
                arquivo << 4 << " " << ponto+3 << " " << ponto+7 << " " << ponto+6 << " " << ponto+2 << " ";
                arquivo << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                //P1 P2 P6 P5
                arquivo << 4 << " " << ponto+1 << " " << ponto+2 << " " << ponto+6 << " " << ponto+5 << " ";
                arquivo << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;

                ponto += 8;
                }

                }
            }
        }

    arquivo.close();
}


