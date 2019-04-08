#include "listafichas.h"
#include <string>
#include <iostream>
#include<QDebug>
using namespace std;


ListaFichas::ListaFichas() {
    head= nullptr;

}
void ListaFichas::addF(QString data, int valor) {

    int posicion[1][1] = {{-1}};
    node *temp = new node(valor, nullptr, data, posicion);
    temp->setDato(data);


    if (head == nullptr) {

        head = temp;



    } else {

        temp->setNext(head);
        head = temp;

    }
}
void ListaFichas::addFF(node* node1) {


    node *temp = node1;



    if (head == nullptr) {

        head = temp;



    } else {

        temp->setNext(head);
        head = temp;

    }
}

node* ListaFichas::deleteFicha(QString data) {
    node *current;
    node *previous;
    current = head;
    while (current->getDato() == data){
        previous = current;
        current = current->getNext();
    }
    previous->setNext(current->getNext());
    return current;
}




