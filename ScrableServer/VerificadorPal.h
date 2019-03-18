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
    static bool buscarPal(char* pal);
    static std::string buscardicc(char* pal);
};


#endif //ABRIRTXT_VERIFICADORPAL_H
