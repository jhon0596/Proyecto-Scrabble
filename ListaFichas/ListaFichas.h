//
// Created by jonathan on 16/03/19.
//

#ifndef LISTAFICHAS_LISTAFICHAS_H
#define LISTAFICHAS_LISTAFICHAS_H

#include "node.h"
#include <string>
#include <iostream>
using namespace std;
class ListaFichas {
private:
    node *head;
public:
    ListaFichas();
    void addF(string data, int valor);
    node* deleteFicha(string data);

};


#endif //LISTAFICHAS_LISTAFICHAS_H
