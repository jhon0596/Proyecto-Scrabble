//
// Created by gacova on 28/03/19.
//

#ifndef SCRABLESERVER_JUEGO_H
#define SCRABLESERVER_JUEGO_H

#include <iostream>

class juego {
public:
    juego(std::string pal,std::string cod);

private:
    std::string codigoEntrada;
    void GenerarMatriz();
    void valPal(std::string pl);
    char met[15][15] ;
    std::string resultado;
public:
    const std::string &getResultado() const;

    char getMatriz(int fil, int col);
    //lista jugadores


};


#endif //SCRABLESERVER_JUEGO_H
