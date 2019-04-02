//
// Created by gacova on 28/03/19.
//

#include "juego.h"
#include "VerificadorPal.h"

juego::juego(std::string pal,std::string cod) {
    this->codigoEntrada=cod;
    this->GenerarMatriz();

    this->valPal(pal);
}

void juego::GenerarMatriz() {

    for (int i = 0; i < 15; i++)
    {

        for (int j = 0; j < 15; j++)
        {
            this->met[i][j]=' ';

        }
}
}

void juego::valPal(std::string pl) {
    if (VerificadorPal::buscarPal(pl)){
        this->resultado ="palabra Encontrada" ;
    } else{this->resultado= "palabra NO Encontrada"; }

}

const std::string &juego::getResultado() const {
    return resultado;
}

char juego::getMatriz(int fil, int col) {
    return this->met[fil][col];
}
