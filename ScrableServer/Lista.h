//
// Created by gacova on 01/04/19.
//

#ifndef SCRABLESERVER_LISTA_H
#define SCRABLESERVER_LISTA_H

template<class T>
struct node {

    node<T>* next;
    T data;
};
template<class T>

class Lista {
public:
    node<T>* first;
    node<T>* last;
    Lista<T>();
    void add(T data);
    T get(int index);
    T operator[](int index);
    void deleteAt();

private:
    int size;
public:
    int getSize() const;

};

template<class T>
Lista<T>::Lista() {
    this->first = nullptr;
    this->last = nullptr;
    size = 0;
}

template<class T>
void Lista<T>::add(T data) {

    if(!this->first) {
        // The list is empty
        this->first = new node<T>;
        this->first->data = data;
        this->first->next = nullptr;
        this->last = this->first;
    } else {
        // The list isn't empty
        if(this->last == this->first) {
            // The list has one element
            this->last = new node<T>;
            this-> last->data = data;
            this->last->next = nullptr;
            this->first->next = this->last;
        } else {
            // The list has more than one element
            node<T> * insdata = new node<T>;

            insdata->data = data;
            insdata->next = nullptr;
            this->last->next = insdata;
            this->last = insdata;
        }
    }
this->size++;
}

template<class T>
T Lista<T>::get(int index) {
    if(index == 0) {
        // Get the first element
        return this->first->data;
    } else {
        // Get the index'th element
        node<T>* curr = this->first;
        for(int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }
}

template<class T>
T Lista<T>::operator[](int index) {
    return get(index);
}

template<class T>
int Lista<T>::getSize() const {
    return size;
}

#endif //SCRABLESERVER_LISTA_H
