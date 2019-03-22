#include "listafichas.h"

#include "listafichas.h"
#include <string>
#include <iostream>
using namespace std;


ListaFichas::ListaFichas() {
    head= nullptr;

}
void ListaFichas::addF(string data, int valor) {

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

node *ListaFichas::deleteFicha(string data) {
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

ListaFichas ListaFichas:: crearLista(){
    ListaFichas listaFichas;
    for(int i = 0; i <=12 ;i++){

        listaFichas.addF("A",1);
        listaFichas.addF("E", 1);
    }
    for (int i = 0; i <= 9; ++i) {
        listaFichas.addF("O",1);
    }

    for (int i = 0; i <= 6; ++i) {
        listaFichas.addF("I",1);
        listaFichas.addF("S",6);
    }
    for (int i = 0; i <= 5; ++i) {
        listaFichas.addF("N",1);
        listaFichas.addF("R",1);
        listaFichas.addF("U",1);
        listaFichas.addF("D",2);
    }
    for (int i = 0; i <= 4; ++i) {
        listaFichas.addF("L",1);
        listaFichas.addF("T",1);
        listaFichas.addF("C",3);
    }
    for (int i = 0; i <= 2; ++i) {
        listaFichas.addF("G",2);
        listaFichas.addF("B",3);
        listaFichas.addF("M",3);
        listaFichas.addF("P",3);
        listaFichas.addF("H",4);
        listaFichas.addF("Comodin",0);
    }
    listaFichas.addF("F",4);
    listaFichas.addF("V",4);
    listaFichas.addF("Y",4);
    listaFichas.addF("Q",5);
    listaFichas.addF("J",8);
    listaFichas.addF("Ñ",8);
    listaFichas.addF("X",8);
    listaFichas.addF("Z",10);
    listaFichas.addF("CH",5);
    listaFichas.addF("LL",8);
    listaFichas.addF("RR",1);
    return listaFichas;
}

