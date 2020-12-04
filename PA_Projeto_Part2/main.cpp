#include <iostream>
#include "interpretador.h"

using namespace std;

int main()
{
    sculptor *s1;

    Interpretador parser;

    vector<FiguraGeometrica*> figs;

    figs = parser.parse("Figuras\\exemplo1.txt");

    s1 = new sculptor(parser.getdimX(),parser.getdimY(),parser.getdimZ());

    for(size_t i = 0; i<figs.size(); i++){
        figs[i]->Draw(*s1);
    }
    s1->LimpaVoxel();

    s1-> writeOFF("Figuras3d\\exemplo3d1.OFF");
    for(size_t i = 0; i<figs.size(); i++){
        delete figs[i];
    }
    delete s1;
    cout << "Concluido!" << endl;
    return 0;
}
