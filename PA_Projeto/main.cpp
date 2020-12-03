#include <iostream>
#include "sculptor.h"
#include <fstream>

//https://agostinhobritojr.github.io/curso/progav-dca1202/escultor.html

using namespace std;

int main()
{

    //teste de cor e opacidade e função putVoxel;
    sculptor col(3,3,1);
    //vermelho
    col.setColor(1,0,0,1);
    col.putVoxel(0,0,0);
    col.setColor(1,0,0,0.5);
    col.putVoxel(0,1,0);
    col.setColor(1,0,0,0.25);
    col.putVoxel(0,2,0);
    //verde
    col.setColor(0,1,0,1);
    col.putVoxel(1,0,0);
    col.setColor(0,1,0,0.5);
    col.putVoxel(1,1,0);
    col.setColor(0,1,0,0.25);
    col.putVoxel(1,2,0);
    //azul
    col.setColor(0,0,1,1);
    col.putVoxel(2,0,0);
    col.setColor(0,0,1,0.5);
    col.putVoxel(2,1,0);
    col.setColor(0,0,1,0.25);
    col.putVoxel(2,2,0);

    col.writeOFF("colortest.OFF");

    //teste box
    sculptor box(5,5,5);
    box.setColor(1,0,1,1);
    box.putBox(0,4,0,4,0,2);
    box.setColor(1,1,0,1);
    box.putBox(0,4,0,2,2,4);
    box.setColor(1,1,1,1);
    box.putBox(0,4,2,4,2,4);

    box.writeOFF("teste_box.OFF");

    //teste cutbox
    box.cutBox(1,3,1,3,1,4);

    box.writeOFF("teste_cutbox.OFF");

    //teste esfera
    sculptor esf(51,51,51);
    esf.setColor(0,1,1,1);
    esf.putSphere(25,25,25,20);

    esf.writeOFF("teste_esfera.OFF");

    //teste cutesfera
    esf.cutSphere(45,45,45,40);

    esf.writeOFF("teste_cutesfera.OFF");

    //teste do elipsoide
    sculptor el(101,101,101);
    el.setColor(0.25,0.6,0.7,1);
    el.putEllipsoid(50,50,50,10,12,20);

    el.writeOFF("teste_elips.OFF");

    //teste cutelipsoide
    el.cutEllipsoid(50,50,50,20,6,10);

    el.writeOFF("teste_cutelips.OFF");

    /*
    sculptor fig(100,100,100);
    //cubo magico

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
    */

    cout << "Ja esta Pronto!" << endl;
    return 0;
}
