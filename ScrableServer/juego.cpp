//
// Created by gacova on 28/03/19.
//

#include "juego.h"
#include "VerificadorPal.h"

char met[15][15] ;


juego::juego(std::string cod) {
    this->codigoEntrada=cod;
    this->GenerarMatriz();

}
juego::juego(){}

void juego::GenerarMatriz() {

    for (int i = 0; i < 15; i++)
    {

        for (int j = 0; j < 15; j++)
        {
            met[i][j]=' ';

        }
}
}


const std::string &juego::getResultado() const {
    return resultado;
}

char juego::getMatriz(int fil, int col) {
    return met[fil][col];
}

const std::string &juego::getCodigoEntrada() const {
    return codigoEntrada;
}

void juego::meterpalabra(int *x, int *y, std::string plb) {
    if (VerificadorPal::buscarPal(plb)){
        this->resultado ="palabra Encontrada" ;
        int px= x[0]-x[1];
        if(px==0){ponerHorizo(x,y,plb);}
        else{ponerVert(x,y,plb);}


    } else{this->resultado= "palabra NO Encontrada"; }


}

void juego::ponerHorizo(int *x, int *y, std::string plb) {
    int ch=0;
for(int pos =y[0];pos<=y[1];pos++){
    met[x[0]][pos]=plb.at(ch);
    ch++;
}
}

void juego::ponerVert(int *x, int *y, std::string plb) {
    int ch=0;
    for(int pos =x[0];pos<=x[1];pos++){
        met[pos][y[0]]=plb.at(ch);
        ch++;
    }
}
