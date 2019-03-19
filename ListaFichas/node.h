//
// Created by jonathan on 16/03/19.
//

#ifndef LISTAFICHAS_NODE_H
#define LISTAFICHAS_NODE_H

#include <string>
#include <iostream>
using namespace std;
class node {
private:
     string data;
    int valor;
    int posicion[1][1];
    node *next;
public:
    /**
 *@brief crea el nodo con el valor indicado y la referencia al siguiente nodo
 * @param pun val (input)
 * */
    node(int valor, node* pun , string data, int posicion[][]);

    /**
     *@brief retorna el valor de su siguiente nodoa
     * */
    node *getNext() const;

    /**
     *@brief asigna el valor al nodo
     * */
    void setDato(string data);

    /**
     *@brief asigna el nodo siguiente
     * */
    void setNext(node* pun);

    /**
     *@brief obtiene el valor del nodo
     * */

    string getDato() ;

    int getValor();

    int setPosicion(int posicion[1][1]);

    int *getPosicion();
};


#endif //LISTAFICHAS_NODE_H
