//
// Created by gacova on 28/03/19.
//

#ifndef SCRABLESERVER_JUEGO_H
#define SCRABLESERVER_JUEGO_H

#include <iostream>

class juego {
public:
    juego();
    juego(std::string pal,std::string cod);
    const std::string &getResultado() const;
    const std::string &getCodigoEntrada() const;
    char getMatriz(int fil, int col);
private:
    std::string codigoEntrada;
    void GenerarMatriz();
    void valPal(std::string pl);
    char met[15][15] ;
    std::string resultado;


    //lista jugadores


};


#endif //SCRABLESERVER_JUEGO_H
