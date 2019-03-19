//
// Created by jonathan on 16/03/19.
//

#include "node.h"
#include <string>
#include <iostream>
using namespace std;
node::node(int valor, node *pun, string data, int posicion[][]) {
    this->data = data;
    this->valor = valor;
    this->next = pun;
    this-> posicion = posicion;
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

int node::setPosicion(int posicion[][]) {
    this->posicion = posicion;
}

int *node::getPosicion() {
    return *posicion;
}




