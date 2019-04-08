#ifndef LISTAFICHAS_H
#define LISTAFICHAS_H


#include "node.h"
#include <string>
#include <iostream>
using namespace std;
class ListaFichas {


public:
     node *head;
    ListaFichas();
    void addF(QString data, int valor);
    node* deleteFicha(QString data);
    void addFF(node* nodo1);

};
#endif // LISTAFICHAS_H
