#ifndef NODE_H
#define NODE_H


#include <string>
#include <iostream>
using namespace std;
class node {
private:
     string data;
    int valor;
    int posicion[1][1] ={{0}};
    node *next;
public:
    /**
 *@brief crea el nodo con el valor indicado y la referencia al siguiente nodo
 * @param pun val (input)
 * */
    node(int valor, node* pun , string data, int posicion[1][1]);

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

    void setPosicion(int posicion[1][1]);

    int *getPosicion();
};

#endif // NODE_H
