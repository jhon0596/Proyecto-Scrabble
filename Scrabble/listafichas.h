#ifndef LISTAFICHAS_H
#define LISTAFICHAS_H


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
   ListaFichas crearLista();
};
#endif // LISTAFICHAS_H
