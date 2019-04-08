//
// Created by gacova on 28/03/19.
//

#ifndef SCRABLESERVER_JUEGO_H
#define SCRABLESERVER_JUEGO_H

#include <iostream>

class juego {
public:
    /**
     *@brief  constructor de juego sin nada
     * */
    juego();
    /**
     *@brief  constructor de juego
     *
     * @param cod codigo de entrada
     * */
    juego(std::string cod);
    /**
     *@brief  devuelve el resultado de la variable resultado
     *
     * */
    const std::string &getResultado() const;
    /**
    *@brief  devuelve el resultado de codigo de entrada
    *
    * */
    const std::string &getCodigoEntrada() const;
    /**
    *@brief  devuelve el valor en la celda de la matriz
    * @param col columna
     * @param fil fila
    * */
    char getMatriz(int fil, int col);
    /**
    *@brief  introduce la palbara en la matriz
    * @param x posicion inicial y final en x
     * @param y posicion inicial y final en y
     * @param plb palabra
    * */
    void meterpalabra(int x[2], int y[2], std::string plb);



private:
    /**
    *@brief  el codigo de entrada
    *
    * */
    std::string codigoEntrada;
    /**
    *@brief  genera la mmatriz vacia
    *
    * */
    void GenerarMatriz();

    /**
    *@brief  variable del resultado
    *
    * */
    std::string resultado;
    /**
    *@brief  introduce la palbara en la matriz de forma horizontal
    * @param x posicion inicial y final en x
     * @param y posicion inicial y final en y
     * @param plb palabra
    * */
    void ponerHorizo(int x[2], int y[2], std::string plb);
    /**
    *@brief  introduce la palbara en la matriz de forma vertical
    * @param x posicion inicial y final en x
     * @param y posicion inicial y final en y
     * @param plb palabra
    * */
    void ponerVert(int x[2], int y[2], std::string plb);

    //lista jugadores


};


#endif //SCRABLESERVER_JUEGO_H
