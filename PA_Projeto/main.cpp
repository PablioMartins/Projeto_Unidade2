#include <iostream>
#include "sculptor.h"
#include <fstream>

//https://agostinhobritojr.github.io/curso/progav-dca1202/escultor.html

using namespace std;

int main()
{
    sculptor fig(100,100,100);

    fig.setColor(0,0,0,0.5);
    fig.putBox(0,34,0,34,0,34);
    //lado vermelho
    fig.setColor(1,0,0,1);
    fig.putBox(1,11,1,11,0,1);
    fig.putBox(12,22,1,11,0,1);
    fig.putBox(23,33,1,11,0,1);
    fig.putBox(1,11,12, 22,0,1);
    fig.putBox(12,22,12,22,0,1);
    fig.putBox(23,33,12,22,0,1);
    fig.putBox(1,11,23,33,0,1);
    fig.putBox(12,22,23,33,0,1);
    fig.putBox(23,33,23,33,0,1);

    //lado verde
    fig.setColor(0,1,0,1);
    fig.putBox(0,1,1,11,1,11);
    fig.putBox(0,1,12,22,1,11);
    fig.putBox(0,1,23,33,1,11);
    fig.putBox(0,1,1,11,12,22);
    fig.putBox(0,1,12,22,12,22);
    fig.putBox(0,1,23,33,12,22);
    fig.putBox(0,1,1,11,23,33);
    fig.putBox(0,1,12,22,23,33);
    fig.putBox(0,1,23,33,23,33);

    //lado azul
    fig.setColor(0,0,1,1);
    fig.putBox(1,11,0,1,1,11);
    fig.putBox(12,22,0,1,1,11);
    fig.putBox(23,33,0,1,1,11);
    fig.putBox(1,11,0,1,12,22);
    fig.putBox(12,22,0,1,12,22);
    fig.putBox(23,33,0,1,12,22);
    fig.putBox(1,11,0,1,23,33);
    fig.putBox(12,22,0,1,23,33);
    fig.putBox(23,33,0,1,23,33);

    //lado amarelo
    fig.setColor(1,1,0,1);
    fig.putBox(1,11,33,34,1,11);
    fig.putBox(12,22,33,34,1,11);
    fig.putBox(23,33,33,34,1,11);
    fig.putBox(1,11,33,34,12,22);
    fig.putBox(12,22,33,34,12,22);
    fig.putBox(23,33,33,34,12,22);
    fig.putBox(1,11,33,34,23,33);
    fig.putBox(12,22,33,34,23,33);
    fig.putBox(23,33,33,34,23,33);

    //lado Branco
    fig.setColor(1,1,1,1);
    fig.putBox(33,34,1,11,1,11);
    fig.putBox(33,34,12,22,1,11);
    fig.putBox(33,34,23,33,1,11);
    fig.putBox(33,34,1,11,12,22);
    fig.putBox(33,34,12,22,12,22);
    fig.putBox(33,34,23,33,12,22);
    fig.putBox(33,34,1,11,23,33);
    fig.putBox(33,34,12,22,23,33);
    fig.putBox(33,34,23,33,23,33);

    //lado Laranja
    fig.setColor(1,0.5,0.25,1);
    fig.putBox(1,11,1,11,33,34);
    fig.putBox(12,22,1,11,33,34);
    fig.putBox(23,33,1,11,33,34);
    fig.putBox(1,11,12, 22,33,34);
    fig.putBox(12,22,12,22,33,34);
    fig.putBox(23,33,12,22,33,34);
    fig.putBox(1,11,23,33,33,34);
    fig.putBox(12,22,23,33,33,34);
    fig.putBox(23,33,23,33,33,34);

    fig.writeOFF("Cubo_Magico.OFF");

    cout << "Ja esta Pronto!" << endl;
    return 0;
}
