//
// Created by gacova on 16/03/19.
//

#ifndef ABRIRTXT_VERIFICADORPAL_H
#define ABRIRTXT_VERIFICADORPAL_H
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>


class VerificadorPal {
public:
    /**
     *@brief busca la palabra en diccionario correcto(depende del primer caracter)
     * @param pal palabra por buscar
     * @return si la palabra ess valida
     * */
    static bool buscarPal(std::string pal);

private:
    /**
     *@brief  busca el diccionario correcto con el primer caracter de la palabra
     * @param pal primer caracter de la palabra
     * @return la direccion fisca del diccionario
     * */
    static std::string buscardicc(char pal);
};


#endif //ABRIRTXT_VERIFICADORPAL_H
