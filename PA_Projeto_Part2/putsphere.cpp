#include "putsphere.h"
#include <cmath>

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a)
{
    this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter; this->radius = radius;
    this->r = r; this->g = g; this->b = b; this->a = a;
}

void PutSphere:: Draw(sculptor &t){
    for(int i = xcenter - radius; i <= xcenter + radius; i++){
        for(int j = ycenter - radius; j <= ycenter + radius; j++){
            for(int k = zcenter - radius; k <= zcenter + radius; k++){
                if(sqrt(pow(i-xcenter,2)+pow(j-ycenter,2)+pow(k-zcenter,2)) <= radius){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}
