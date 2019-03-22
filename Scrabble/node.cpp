#include "node.h"

#include <string>
#include <iostream>
using namespace std;
node::node(int valor, node *pun, string data, int posicion[1][1]) {
    this->data = data;
    this->valor = valor;
    this->next = pun;
    this->posicion[0][0]=posicion[1][1];
}

void node::setDato(string data) {
    this->data =data;
}

node *node::getNext() const {
    return next;
}

void node::setNext(node *pun) {
    this->next=pun;
}

string node::getDato() {
    return data;
}
int node::getValor()  {
    return valor;
}

void node::setPosicion(int posicion[1][1]) {
     this->posicion[0][0]=posicion[1][1];
}

int *node::getPosicion() {
    return *posicion;
}
